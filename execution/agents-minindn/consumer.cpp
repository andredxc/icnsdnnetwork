/*
*   Vanilla consumer for MiniNDN
*
*
*/
#include <ndn-cxx/face.hpp>
#include <iostream>
#include <chrono>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces should be used to prevent/limit name conflicts
namespace examples {

class Consumer
{
  public:
    void run(std::string strInterest, std::string strNode);

  private:
    void onData(const Interest&, const Data& data)     const;
    void onNack(const Interest&, const lp::Nack& nack) const;
    void onTimeout(const Interest& interest)           const;

  private:
    Face m_face;
    std::string m_strNode;
};

// --------------------------------------------------------------------------------
//  run
//
//
// --------------------------------------------------------------------------------
void Consumer::run(std::string strInterest, std::string strNode)
{
  Name     interestName;
  Interest interest;
  float    sTimeDiff;
  FILE*    pFile;
  char     strFile[50];
  std::chrono::steady_clock::time_point dtBegin;
  std::chrono::steady_clock::time_point dtEnd;

  if (strInterest.length() == 0){
    // No specific interest given as parameter
    strInterest = "/example/testApp2/randomData";
  }

  fprintf(stderr, "[Consumer::run] Consuming interest=%s; node=%s", strInterest.c_str(), strNode.c_str());

  interestName = Name(strInterest);
  // interestName.appendVersion();

  interest = Interest(interestName);
  interest.setCanBePrefix(false);
  interest.setMustBeFresh(true);
  interest.setInterestLifetime(6_s); // The default is 4 seconds

  dtBegin = std::chrono::steady_clock::now();
  m_face.expressInterest(interest,
                         bind(&Consumer::onData, this,  _1, _2),
                         bind(&Consumer::onNack, this, _1, _2),
                         bind(&Consumer::onTimeout, this, _1));

  std::cout << "Sending Interest " << interest << std::endl;
  // processEvents will block until the requested data is received or a timeout occurs
  m_face.processEvents();

  dtEnd      = std::chrono::steady_clock::now();
  sTimeDiff  = std::chrono::duration_cast<std::chrono::microseconds>(dtEnd - dtBegin).count();

  std::cout << "Time elapsed:" << sTimeDiff << std::endl;

  if (strNode.length() > 0){
    // Write results to file
    snprintf(strFile, sizeof(strFile), "/tmp/minindn/%s/consumerLog.log", strNode.c_str());
    fprintf(stderr, "[Consumer::run] writing time output to file=%s\n", strFile);
    pFile = fopen(strFile, "a");  // TODO: relative path might not work

    if (pFile){
      fprintf(pFile, "%s;%.3f", strInterest.c_str(), sTimeDiff);
      fclose(pFile);
    }
    else{
      std::cout << "Consumer::run ERROR opening output file" << std::endl;
    }
  }
}

// --------------------------------------------------------------------------------
//  onData
//
//
// --------------------------------------------------------------------------------
void Consumer::onData(const Interest&, const Data& data) const
{
  std::cout << "[Consumer::onData] Received Data " << data << std::endl;
}

// --------------------------------------------------------------------------------
//  onNack
//
//
// --------------------------------------------------------------------------------
void Consumer::onNack(const Interest&, const lp::Nack& nack) const
{
  std::cout << "[Consumer::onNack] Received Nack with reason " << nack.getReason() << std::endl;
}

// --------------------------------------------------------------------------------
//  onTimeout
//
//
// --------------------------------------------------------------------------------
void Consumer::onTimeout(const Interest& interest) const
{
  std::cout << "[Consumer::onTimeout] Timeout for " << interest << std::endl;
}

} // namespace examples
} // namespace ndn

int main(int argc, char** argv)
{
  std::string strInterest;
  std::string strNode;

  if (argc > 2){
    // Use explicit interest and node name
    strInterest = argv[1];
    strNode     = argv[2];
  }
  else{
    strInterest = "";
    strNode     = "";
  }

  try {
    ndn::examples::Consumer consumer;
    consumer.run(strInterest, strNode);
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "[main] ERROR: " << e.what() << std::endl;
    return 1;
  }
}
