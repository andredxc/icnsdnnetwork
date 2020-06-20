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
  void run(std::string strInterest)
  {
    Name     interestName;
    Interest interest;
    float    dtTimeDiff;
    FILE*    pFile;
    std::chrono::steady_clock::time_point dtBegin;
    std::chrono::steady_clock::time_point dtEnd;

    if (strInterest.length() == 0){
      // No specific interest given as parameter
      strInterest = "/example/testApp2/randomData";
    }

    interestName = Name(strInterest);
    interestName.appendVersion();

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
    dtTimeDiff = std::chrono::duration_cast<std::chrono::microseconds>(dtEnd - dtBegin).count();

    std::cout << "Time elapsed:" << dtTimeDiff << std::endl;

    // Write results to file
    pFile = fopen("~/consumerOut.log", "a");  // TODO: relative path might not work

    if(pFile){
      fprintf(pFile, "%s;%.3f", strInterest.c_str(), dtTimeDiff);
      fclose(pFile);
    }
    else{
      std::cout << "Consumer::run ERROR opening output file" << std::endl;
    }
  }

private:
  void
  onData(const Interest&, const Data& data) const
  {
    std::cout << "Received Data " << data << std::endl;
  }

  void
  onNack(const Interest&, const lp::Nack& nack) const
  {
    std::cout << "Received Nack with reason " << nack.getReason() << std::endl;
  }

  void
  onTimeout(const Interest& interest) const
  {
    std::cout << "Timeout for " << interest << std::endl;
  }

private:
  Face m_face;
};

} // namespace examples
} // namespace ndn

int
main(int argc, char** argv)
{
  std::string strInterest;

  if (argc > 1){
    strInterest = argv[1];
  }
  else{
    strInterest = "";
  }

  try {
    ndn::examples::Consumer consumer;
    consumer.run(strInterest);
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
}
