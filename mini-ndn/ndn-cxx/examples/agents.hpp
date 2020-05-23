#include "face.hpp"
#include "security/key-chain.hpp"

#include <iostream>
#include <thread>
#include <string.h>


// Avoid namespace conflicts within ndn
namespace ndn{
namespace example{


class Consumer : noncopyable
{
    private:
    void onData   (const Interest& interest, const Data& data);
    void onNack   (const Interest& interest, const lp::Nack& nack);
    void onTimeout(const Interest& interest);
    
    public:
    float run(std::string param);

    private:
    Face        m_face;
    std::string parameter = "";
};


class Producer : noncopyable
{
    private:
    void onInterest      (const InterestFilter& filter, const Interest& interest)   
    void onRegisterFailed(const Name& prefix, const std::string& reason)
    
    public: 
    void registerData(Data d);
    void run         (std::string param = "");

    private:
    Face                  m_face;
    KeyChain              m_keyChain;
    std::thread           ithread;
    std::shared_ptr<Data> data_;
};


// End namespaces
}}