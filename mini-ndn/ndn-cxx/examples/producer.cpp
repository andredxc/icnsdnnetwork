/*
*
*   Versão do Gabriel ICN + SDN
*
*/

// correct way to include ndn-cxx headers
// #include <ndn-cxx/face.hpp>
// #include <ndn-cxx/security/key-chain.hpp>
#include "face.hpp"
#include "security/key-chain.hpp"

#include <iostream>
#include <thread>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces can be used to prevent/limit name conflicts
namespace examples {

class Producer : noncopyable
{
public:
  /*
  * Producer::run
  */
  void run(std::string param = "")
  {
    int nID, nParams;

    if (data_ != nullptr)
    {
      param = "";
      std::ostringstream os;
      if (data_->getName().empty()) {
      os << "/";
      }
      else {
        for (const auto& component : data_->getName()) {
          os << "/";
          component.toUri(os);
        }
      }
      param = os.str();
    }

    // Identify data type from string
    nParams = sscanf(param, "C2Data-%d-Type%d", &nID, &m_nDataType);

    if (nParams = 0){
      // C2DataType was not present, disable
      m_nDataType = -1;
    }

    m_face.setInterestFilter("/"+param +"/",
                             bind(&Producer::onInterest, this, _1, _2),
                             RegisterPrefixSuccessCallback(),
                             bind(&Producer::onRegisterFailed, this, _1, _2));
    m_face.processEvents();
  }

  /*
  * Producer::run_thread
  */
  void run_thread(Data d)
  {
    data_ = make_shared<Data> (d);
    ithread = std::thread(&ndn::examples::Producer::run, this, "");
  }

private:
  /*
  * Producer::onInterest
  */
  void onInterest(const InterestFilter& filter, const Interest& interest)
  {
    static const std::string strContent;

    std::cout << "<< I: " << interest << std::endl;

    // Create new name, based on Interest's name
    Name dataName(interest.getName());
    dataName
      .append("testApp") // add "testApp" component to Interest name
      .appendVersion();  // add "version" component (current UNIX timestamp in milliseconds)

    if (data_ == nullptr){

      // Create Data packet
      data_ = make_shared<Data>();
      data_->setName(dataName);
      data_->setFreshnessPeriod(0_s); // 10 seconds

      if (m_nDataType >= 0){
        // C2DataType is enabled
        // TODO: Add verification to check if N_PAYLOAD_QTD is aligned between random_talks and here
        strContent = "C2 DATA!";
        // data_->setContent(reinterpret_cast<const uint8_t*>(strContent.data()), strContent.size());
      }
      else{
        // Standard data
        strContent = "HELLO KITTY!";
        data_->setContent(reinterpret_cast<const uint8_t*>(strContent.data()), strContent.size());
      }
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
  * Producer::onRegisterFailed
  */
  void onRegisterFailed(const Name& prefix, const std::string& reason)
  {
    std::cerr << "ERROR: Failed to register prefix \""
              << prefix << "\" in local hub's daemon (" << reason << ")"
              << std::endl;
    m_face.shutdown();
  }

private:
  int m_nDataType;
  Face m_face;
  KeyChain m_keyChain;
  std::thread ithread;
  std::shared_ptr<Data> data_;
};

class Consumer : noncopyable
{
public:
  float
  run(std::string param = "")
  {
    Interest interest(Name("/"+param));
    interest.setInterestLifetime(2_s); // 2 seconds
    interest.setCanBePrefix(true);
    interest.setMustBeFresh(true);

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
    return time_diff;
  }

private:
  void
  onData(const Interest& interest, const Data& data)
  {
    std::cout << data << std::endl;
    //Producer producer;

    //producer.run_thread(data);
  }

  void
  onNack(const Interest& interest, const lp::Nack& nack)
  {
    std::cout << "received Nack with reason " << nack.getReason()
              << " for interest " << interest << std::endl;
  }

  void
  onTimeout(const Interest& interest)
  {
    std::cout << "Timeout " << interest << std::endl;
  }

private:
  Face m_face;
};


} // namespace examples
} // namespace ndn

int
main(int argc, char** argv)
{
  ndn::examples::Producer producer;
  try {
    if ( argc > 1 )
    {
      std::string param(argv[1]);
      producer.run(param);
    }
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
  return 0;
}
