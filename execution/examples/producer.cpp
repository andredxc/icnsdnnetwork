/*
*   Vanilla producer for MiniNDN
*
*
*/

#include <ndn-cxx/face.hpp>
#include <ndn-cxx/security/key-chain.hpp>
#include <ndn-cxx/security/signing-helpers.hpp>

#include <iostream>

#define STR_APPNAME "C2Data"

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces should be used to prevent/limit name conflicts
namespace examples {

class Producer
{
  public:
    void run(std::string strFilter);

  private:
    void onInterest(const InterestFilter&, const Interest& interest);
    void onRegisterFailed(const Name& prefix, const std::string& reason);

  private:
    Face     m_face;
    KeyChain m_keyChain;
};

// --------------------------------------------------------------------------------
//  run
//
//
// --------------------------------------------------------------------------------
void Producer::run(std::string strFilter)
{
  int nParams, nID;

  if (strFilter.length() == 0){
    // No specific filter set
    strFilter = "/exampleApp/blup";
  }

  fprintf(stderr, "[Producer::run] Producer for filter=%s", strFilter.c_str())

  // strInterest = '/' + c_strAppName + '/' + str(producer) + '/' + strInterest
  m_face.setInterestFilter(strFilter,
                           bind(&Producer::onInterest, this, _1, _2),
                           nullptr, // RegisterPrefixSuccessCallback is optional
                           bind(&Producer::onRegisterFailed, this, _1, _2));
  m_face.processEvents();
}

// --------------------------------------------------------------------------------
//  onInterest
//
//
// --------------------------------------------------------------------------------
void Producer::onInterest(const InterestFilter&, const Interest& interest)
{
  static std::string strContent; // This used to be a const, might be a problem
  int nType, nID, nRead;
  auto data;

  std::cout << ">> I: " << interest << std::endl;

  nRead = sscanf(interest, "C2Data-%d-Type%d", &nID, &nType)

  if (nRead > 0){
    // Use C2 data
    strContent = "C2Data";
  }
  else{
    // Use random data to keep retro-compatibility
    strContent = "Hello, world!";
  }

  // Create Data packet
  data = make_shared<Data>(interest.getName());
  data->setFreshnessPeriod(10_s);
  data->setContent(reinterpret_cast<const uint8_t*>(strContent.data()), strContent.size());

  // Sign Data packet with default identity
  m_keyChain.sign(*data);
  // m_keyChain.sign(*data, signingByIdentity(<identityName>));
  // m_keyChain.sign(*data, signingByKey(<keyName>));
  // m_keyChain.sign(*data, signingByCertificate(<certName>));
  // m_keyChain.sign(*data, signingWithSha256());

  // Return Data packet to the requester
  std::cout << "<< D: " << *data << std::endl;
  m_face.put(*data);
}

// --------------------------------------------------------------------------------
//  onRegisterFailed
//
//
// --------------------------------------------------------------------------------
void Producer::onRegisterFailed(const Name& prefix, const std::string& reason)
{
  std::cerr << "ERROR: Failed to register prefix '" << prefix
            << "' with the local forwarder (" << reason << ")" << std::endl;
  m_face.shutdown();
}

} // namespace examples
} // namespace ndn

int main(int argc, char** argv)
{
  std::string strFilter;

  if (argc > 1){
    // Filter as command line parameter
    strFilter = argv[1];
  }
  else{
    // No data name
    strFilter = "";
  }

  try {
    ndn::examples::Producer producer;
    producer.run(strFilter);
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
}
