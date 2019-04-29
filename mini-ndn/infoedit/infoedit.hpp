/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright 2015, Regents of the University of California.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this
 * file except in compliance with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under
 * the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the specific language governing
 * permissions and limitations under the License.
 */

#ifndef INTEGRATION_TESTS_INSTALL_HELPERS_INFOEDIT_INFOEDIT_HPP
#define INTEGRATION_TESTS_INSTALL_HELPERS_INFOEDIT_INFOEDIT_HPP

#include <fstream>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>

namespace infoedit {

class InfoEditor
{
public:
  class Error : public std::runtime_error
  {
  public:
    Error(const std::string& what)
      : std::runtime_error(what)
    {
    }
  };

public:
  void
  load(const std::string& fileName);

  InfoEditor&
  modify(const std::string& section, const std::string& value);

  InfoEditor&
  add(const std::string& section, const std::string& value);

  InfoEditor&
  remove(const std::string& section);

  InfoEditor&
  insert(const std::string& section, std::istream& stream);

  void
  save(const std::string& fileName);

private:
  boost::property_tree::ptree m_info;
};

} // namespace infoedit

#endif // INTEGRATION_TESTS_INSTALL_HELPERS_INFOEDIT_INFOEDIT_HPP
