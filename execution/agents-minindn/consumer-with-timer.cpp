/*
*   Vanilla consumer-with-timer for MiniNDN
*
*
*/


#include <ndn-cxx/face.hpp>
#include <ndn-cxx/util/scheduler.hpp>

#include <boost/asio/io_service.hpp>
#include <iostream>

// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces should be used to prevent/limit name conflicts
namespace examples {

class ConsumerWithTimer
{
public:
  ConsumerWithTimer()
    : m_face(m_ioService) // Create face with io_service object
    , m_scheduler(m_ioService)
  {
  }

  void
  run()
  {
    Name interestName("/example/testApp/randomData");
    interestName.appendVersion();

    Interest interest(interestName);
    interest.setCanBePrefix(false);
    interest.setMustBeFresh(true);
    interest.setInterestLifetime(2_s);

    std::cout << "Sending Interest " << interest << std::endl;
    m_face.expressInterest(interest,
                           bind(&ConsumerWithTimer::onData, this, _1, _2),
                           bind(&ConsumerWithTimer::onNack, this, _1, _2),
                           bind(&ConsumerWithTimer::onTimeout, this, _1));

    // Schedule a new event
    m_scheduler.schedule(3_s, [this] { delayedInterest(); });

    // m_ioService.run() will block until all events finished or m_ioService.stop() is called
    m_ioService.run();

    // Alternatively, m_face.processEvents() can also be called.
    // processEvents will block until the requested data received or timeout occurs.
    // m_face.processEvents();
  }

private:
  void
  onData(const Interest&, const Data& data) const
  {
    std::cout << "Received Data " << data << std::endl;
  }

  void
  onNack(const Interest& interest, const lp::Nack& nack) const
  {
    std::cout << "Received Nack with reason " << nack.getReason()
              << " for " << interest << std::endl;
  }

  void
  onTimeout(const Interest& interest) const
  {
    std::cout << "Timeout for " << interest << std::endl;
  }

  void
  delayedInterest()
  {
    std::cout << "One more Interest, delayed by the scheduler" << std::endl;

    Name interestName("/example/testApp/randomData");
    interestName.appendVersion();

    Interest interest(interestName);
    interest.setCanBePrefix(false);
    interest.setMustBeFresh(true);
    interest.setInterestLifetime(2_s);

    std::cout << "Sending Interest " << interest << std::endl;
    m_face.expressInterest(interest,
                           bind(&ConsumerWithTimer::onData, this, _1, _2),
                           bind(&ConsumerWithTimer::onNack, this, _1, _2),
                           bind(&ConsumerWithTimer::onTimeout, this, _1));
  }

private:
  // Explicitly create io_service object, which will be shared between Face and Scheduler
  boost::asio::io_service m_ioService;
  Face m_face;
  Scheduler m_scheduler;
};

} // namespace examples
} // namespace ndn

int
main(int argc, char** argv)
{
  try {
    ndn::examples::ConsumerWithTimer consumer;
    consumer.run();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }
}
