/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2013-2018 Regents of the University of California.
 *
 * This file is part of ndn-cxx library (NDN C++ library with eXperimental eXtensions).
 *
 * ndn-cxx library is free software: you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * ndn-cxx library is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.
 *
 * You should have received copies of the GNU General Public License and GNU Lesser
 * General Public License along with ndn-cxx, e.g., in COPYING.md file.  If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * See AUTHORS.md for complete list of ndn-cxx authors and contributors.
 *
 * @author Alexander Afanasyev <http://lasr.cs.ucla.edu/afanasyev/index.html>
 */

// correct way to include ndn-cxx headers
// #include <ndn-cxx/face.hpp>
#include "face.hpp"
#include "security/key-chain.hpp"

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <thread>
#include <unistd.h>


// Enclosing code in ndn simplifies coding (can also use `using namespace ndn`)
namespace ndn {
// Additional nested namespaces can be used to prevent/limit name conflicts
namespace examples {

class Producer : noncopyable
{
public:
  void
  run(std::string param = "")
  {
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

    m_face.setInterestFilter("/" + param + "/",
                             bind(&Producer::onInterest, this, _1, _2),
                             RegisterPrefixSuccessCallback(),
                             bind(&Producer::onRegisterFailed, this, _1, _2));

    m_face.processEvents();
  }

  void
  run_thread(Data d)
  {
    data_ = make_shared<Data> (d);
    ithread = std::thread(&ndn::examples::Producer::run, this, "");
    ithread.join();
  }

private:
  void
  onInterest(const InterestFilter& filter, const Interest& interest)
  {
    std::cout << "<< I: " << interest << std::endl;

    // Create new name, based on Interest's name
    Name dataName(interest.getName());
    dataName
      .append("testApp") // add "testApp" component to Interest name
      .appendVersion();  // add "version" component (current UNIX timestamp in milliseconds)

    if ( data_ == nullptr ){
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


  void
  onRegisterFailed(const Name& prefix, const std::string& reason)
  {
    std::cerr << "ERROR: Failed to register prefix \""
              << prefix << "\" in local hub's daemon (" << reason << ")"
              << std::endl;
    m_face.shutdown();
  }

private:
  Face m_face;
  KeyChain m_keyChain;
  std::thread ithread;
  std::shared_ptr<Data> data_;
};

class Consumer : noncopyable
{
public:
  /*
  *   Consumer::run
  */
  float run(std::string param = "")
  {
    std::chrono::steady_clock::time_point dtBegin;
    std::chrono::steady_clock::time_point dtEnd;
    // previously auto time_diff;
    std::chrono::duration_cast<std::chrono::microseconds> dtTimeDiff;
    FILE* pFile;

    Interest interest(Name("/"+param));
    interest.setInterestLifetime(2_s); // 2 seconds
    interest.setCanBePrefix(true);
    interest.setMustBeFresh(true);

    dtBegin = std::chrono::steady_clock::now();
    m_face.expressInterest(interest,
                           bind(&Consumer::onData, this,  _1, _2),
                           bind(&Consumer::onNack, this, _1, _2),
                           bind(&Consumer::onTimeout, this, _1));

    std::cout << "Sending " << interest << std::endl;

    // processEvents will block until the requested data received or timeout occurs
    m_face.processEvents();
    dtEnd      = std::chrono::steady_clock::now();
    dtTimeDiff = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

    std::cout << "Time elapsed:" << dtTimeDiff << std::endl;

    // Write results to file
    pFile = fopen("~/consumerOut.log", "a");  // TODO: relative path might not work

    if(pFile){
      fprintf(pFile, "%s;%d", param.c_str(), dtTimeDiff);
      fclose(pFile);
    }
    else{
      std::cout << "Consumer::run ERROR opening output file" << std::endl;
    }
    return dtTimeDiff;
  }

private:
  /*
  *   Consumer::onData
  */
  void onData(const Interest& interest, const Data& data)
  {
    std::cout << data << std::endl;
    //Producer producer;

    // Access C2 with data.getContent maybe

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
  ndn::examples::Consumer consumer;
  try {
    if ( argc > 1 )
    {
      std::string param(argv[1]);
      int times[] = {10, 100, 1000, 10000};
      std::vector<float> means, std_dev;
      for(int p = 0; p < 4; p++)
      {
        std::vector<float> total;
        float sum = 0, mean, standard_deviation = 0;

        for( int i = 0; i<times[p]; i++ )
        {
            total.push_back( consumer.run(param) );
            sum += total[i];
            usleep(2000);
        }

        mean = sum/times[p];
        means.push_back(mean);

        for(int i=0; i<times[p]; i++){
            standard_deviation += pow(total[i] - mean, 2);
          }
        std_dev.push_back(sqrt(standard_deviation / times[p]));

        std::cout << "Total time: " << sum/1000 << std::endl;
      }
      for(int p = 0; p < 4; p++)
      {
          std::cout << times[p] << "- Mean: " << means[p]/1000 <<"\n Standard deviation: " << std_dev[p]/1000 << std::endl;
      }
    }
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
  return 0;
}
