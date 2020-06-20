/*
*   Vanilla producer for MiniNDN
*
*
*/

#include <ndn-cxx/face.hpp>
#include <ndn-cxx/security/key-chain.hpp>
#include <ndn-cxx/security/signing-helpers.hpp>

#include <iostream>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces should be used to prevent/limit name conflicts
namespace examples {

class Producer
{
public:
  void run(std::string strParam)
  {
    int nParams, nID;

    // Identify data type from string
    nParams = sscanf(strParam.data(), "C2Data-%d-Type%d", &nID, &m_nDataType);

    if (nParams == 0){
      // C2DataType was not present, disable
      m_nDataType = -1;
      fprintf(stderr, "Producer for default data");
    }
    else{
      // Using C2 data
      fprintf(stderr, "Producer for C2Data=%s; nID=%d; nDataType=%d", strParam.c_str(), nID,
        m_nDataType);
    }

    // TODO: add interest filter based on node name received as argv paramenter
    m_face.setInterestFilter("/example/testApp",
                             bind(&Producer::onInterest, this, _1, _2),
                             nullptr, // RegisterPrefixSuccessCallback is optional
                             bind(&Producer::onRegisterFailed, this, _1, _2));
    m_face.processEvents();
  }

private:
  void onInterest(const InterestFilter&, const Interest& interest)
  {
    static std::string strContent; // This used to be a const, might be a problem

    std::cout << ">> I: " << interest << std::endl;

    if (m_nDataType >= 0){
      // Use C2 data
      strContent = "C2Data";
    }
    else{
      // Use random data to keep retro-compatibility
       strContent = "Hello, world!";
    }

    // Create Data packet
    auto data = make_shared<Data>(interest.getName());
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

  void onRegisterFailed(const Name& prefix, const std::string& reason)
  {
    std::cerr << "ERROR: Failed to register prefix '" << prefix
              << "' with the local forwarder (" << reason << ")" << std::endl;
    m_face.shutdown();
  }

private:
  Face     m_face;
  KeyChain m_keyChain;
  int      m_nDataType;
};

} // namespace examples
} // namespace ndn

int main(int argc, char** argv)
{
  std::string strParam;

  if (argc > 2){
    // Data name as parameter
    strParam = argv[1];
  }
  else{
    // No data name
    strParam = "";
  }

  try {
    ndn::examples::Producer producer;
    producer.run(strParam);
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
}
