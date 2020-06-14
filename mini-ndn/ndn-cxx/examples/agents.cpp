#include "face.hpp"
#include "security/key-chain.hpp"

#include <iostream>
#include <thread>
#include <string.h>

#define N_PAYLOAD_QTD 6
#define N_PAYLOAD0_SIZE 10
#define N_PAYLOAD1_SIZE 10
#define N_PAYLOAD2_SIZE 10
#define N_PAYLOAD3_SIZE 10
#define N_PAYLOAD4_SIZE 10
#define N_PAYLOAD5_SIZE 10

typedef struct C2Data{
    std::string strLabel;
    int         nSizeBytes;
    void*       pPayload;
}C2DATA;

bool g_bInitialized = false;


// Avoid namespace conflicts within ndn
namespace ndn{
namespace examples{


class Consumer : noncopyable
{
    private:
    void onData   (const Interest& interest, const Data& data);
    void onNack   (const Interest& interest, const lp::Nack& nack);
    void onTimeout(const Interest& interest);

    public:
    float run(std::string param = "");

    private:
    Face        m_face;
    std::string parameter = "";
};

class Producer : noncopyable
{
    private:
    void onInterest      (const InterestFilter& filter, const Interest& interest);
    void onRegisterFailed(const Name& prefix, const std::string& reason);

    public:
    void registerData(Data d);
    void run         (std::string param = "");

    private:
    Face                  m_face;
    KeyChain              m_keyChain;
    std::thread           ithread;
    std::shared_ptr<Data> data_;
};

class C2DataTypes : noncopyable
{
    private:
    void* m_arrPayloads[N_PAYLOAD_QTD];

    public:
    C2DataTypes();
    ~C2DataTypes();

    C2DATA* generatePackage(int nType);
};

/*
*   Consumer ---------------------------------------------------------------------------------------
*/

/*
*   Consumer::run
*/
float Consumer::run(std::string param)
{
  if( !param.empty() )
    parameter = param;

  Interest interest(Name("/"+param));
  interest.setInterestLifetime(2_s); // 2 seconds
  interest.setCanBePrefix(true);
  interest.setMustBeFresh(true);


    /**/
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << "Time:" << time_diff << std::endl;


  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  m_face.expressInterest(interest,
                         bind(&Consumer::onData, this,  _1, _2),
                         bind(&Consumer::onNack, this, _1, _2),
                         bind(&Consumer::onTimeout, this, _1));

  std::cout << "Sending " << interest << std::endl;

  // processEvents will block until the requested data received or timeout occurs
  m_face.processEvents();
  std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  auto time_diff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

  std::cout << "Time:" << time_diff << std::endl;
  return time_diff;
}

/*
*   Consumer::onData
*/
void Consumer::onData(const Interest& interest, const Data& data)
{
  std::cout << data << std::endl;
  // ndn::examples::Producer producer;
  // producer.registerData(data);

  // auto ithread = std::thread(&ndn::examples::Producer::run, &producer, parameter);
  // ithread.join();
}

/*
*   Consumer::onNack
*/
void Consumer::onNack(const Interest& interest, const lp::Nack& nack)
{
  std::cout << "received Nack with reason " << nack.getReason()
            << " for interest " << interest << std::endl;
}

/*
*   Consumer::onTimeout
*/
void Consumer::onTimeout(const Interest& interest)
{
  std::cout << "Timeout " << interest << std::endl;
}

/*
*   Producer ---------------------------------------------------------------------------------------
*/

/*
*   Producer::registerData
*/
void Producer::registerData(Data d)
{
    data_ = make_shared<Data> (d);
}

/*
*   Producer::run
*/
void Producer::run(std::string param)
{
    if(!g_bInitialized)
    {
        ndn::examples::Consumer consumer;
        auto ithread = std::thread(&ndn::examples::Consumer::run, &consumer, "controladd"+param);
        ithread.join();
        g_bInitialized = true;
    }

    if (data_ != nullptr)
    {
        param = "";
        std::ostringstream os;
        if (data_->getName().empty()) {
            os << "/";
        }
        else {
            for (const auto& component : data_->getName()){
                os << "/";
                component.toUri(os);
            }
        }
        param = os.str();
    }

    m_face.setInterestFilter("/"+param +"/",
        bind(&Producer::onInterest, this, _1, _2), RegisterPrefixSuccessCallback(),
        bind(&Producer::onRegisterFailed, this, _1, _2));

    m_face.processEvents();
}

/*
*   Producer::onInterest
*/
void Producer::onInterest(const InterestFilter& filter, const Interest& interest)
{
    std::cout << "<< I: " << interest << std::endl;

    // Create new name, based on Interest's name
    Name dataName(interest.getName());
    dataName
        .append("testApp") // add "testApp" component to Interest name
        .appendVersion();  // add "version" component (current UNIX timestamp in milliseconds)

    if (data_ == nullptr)
    {
        static const std::string content = "HELLO KITTY!";

        // Create Data packet
        data_ = make_shared<Data>();
        data_->setName(dataName);
        data_->setFreshnessPeriod(0_s); // 10 seconds
        data_->setContent(reinterpret_cast<const uint8_t*>(content.data()), content.size());
    }

    // Sign Data packet with default identity
    m_keyChain.sign(*data_);
    // m_keyChain.sign(data, <identityName>);
    // m_keyChain.sign(data, <certificate>);

    // Return Data packet to the requester
    std::cout << ">> D: " << *data_ << std::endl;
    m_face.put(*data_);
}

/*
*   Producer::onRegisterField
*/
void Producer::onRegisterFailed(const Name& prefix, const std::string& reason)
{
    std::cerr << "ERROR: Failed to register prefix \"" << prefix << "\" in local hub's daemon ("
        << reason << ")" << std::endl;

    m_face.shutdown();
}

/*
*   C2DataTypes ------------------------------------------------------------------------------------
*/

/*
*   C2DataTypes::C2DataTypes
*/
C2DataTypes::C2DataTypes()
{
    // Allocate possible payloads
    m_arrPayloads[0] = (void*)malloc(N_PAYLOAD0_SIZE);
    m_arrPayloads[1] = (void*)malloc(N_PAYLOAD1_SIZE);
    m_arrPayloads[2] = (void*)malloc(N_PAYLOAD2_SIZE);
    m_arrPayloads[3] = (void*)malloc(N_PAYLOAD3_SIZE);
    m_arrPayloads[4] = (void*)malloc(N_PAYLOAD4_SIZE);
    m_arrPayloads[5] = (void*)malloc(N_PAYLOAD5_SIZE);
}

/*
*   C2DataTypes::generatePackage
*/
C2DATA* C2DataTypes::generatePackage(int nType)
{
    C2DATA* pC2Data;

    pC2Data = (C2DATA*)malloc(sizeof(pC2Data));

    switch(nType){
        case 1:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[0];
            pC2Data->nSizeBytes = N_PAYLOAD0_SIZE;
            break;
        case 2:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[1];
            pC2Data->nSizeBytes = N_PAYLOAD1_SIZE;
            break;
        case 3:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[2];
            pC2Data->nSizeBytes = N_PAYLOAD2_SIZE;
            break;
        case 4:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[3];
            pC2Data->nSizeBytes = N_PAYLOAD3_SIZE;
            break;
        case 5:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[4];
            pC2Data->nSizeBytes = N_PAYLOAD4_SIZE;
            break;
        case 6:
            pC2Data->strLabel   = "aindaNaoSei";
            pC2Data->pPayload   = m_arrPayloads[5];
            pC2Data->nSizeBytes = N_PAYLOAD5_SIZE;
            break;
        default:
            free(pC2Data);
            pC2Data = NULL;
            std::cout << "Error, data type unknown nType=" << nType << std::endl;
    }
    return pC2Data;
}

// End namespaces
}}

/*
*   Main -------------------------------------------------------------------------------------------
*/
int main(int argc, char** argv)
{
  ndn::examples::Producer producer;
  ndn::examples::Consumer consumer;

  try {
    if ( argc > 1 )
    {
      std::string type(argv[1]);
      std::string param(argv[2]);
      int times = std::stoi(argv[3]);
      for(int i=0;i<times;i++)
      {
        std::thread ithread;
        if (type == "producer")
          ithread = std::thread(&ndn::examples::Producer::run, &producer, param);
        else if (type == "consumer")
          ithread = std::thread(&ndn::examples::Consumer::run, &consumer, param);

        std::cout << type << " " << param << std::endl;

        ithread.join();
      }
    }
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
}