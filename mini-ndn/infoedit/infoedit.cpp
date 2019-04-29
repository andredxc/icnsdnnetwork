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

#include "infoedit.hpp"
#include <iostream>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

namespace infoedit {

void
InfoEditor::load(const std::string& fileName)
{
  std::ifstream input(fileName);
  if (!input.good() || !input.is_open()) {
    throw Error("Failed to open configuration file for parsing");
  }

  try {
    boost::property_tree::info_parser::read_info(input, m_info);
  }
  catch (boost::property_tree::info_parser::info_parser_error& error) {
    std::stringstream msg;
    msg << "Failed to parse configuration file";
    msg << " " << error.message() << " line " << error.line();
    throw Error(msg.str());
  }

  input.close();
}

InfoEditor&
InfoEditor::modify(const std::string& section, const std::string& value)
{
  m_info.put(section.c_str(), value.c_str());
  return *this;
}

InfoEditor&
InfoEditor::add(const std::string& section, const std::string& value)
{
  m_info.add(section.c_str(), value.c_str());
  return *this;
}

InfoEditor&
InfoEditor::remove(const std::string& section)
{
  std::size_t pos = section.find_last_of(".");
  if (pos == std::string::npos) {
    m_info.erase(section.c_str());
  }
  else {
    boost::optional<boost::property_tree::ptree&> child =
      m_info.get_child_optional(section.substr(0, pos));
    if (child) {
      child->erase(section.substr(pos + 1));
    }
  }

  return *this;
}

InfoEditor&
InfoEditor::insert(const std::string& section, std::istream& stream)
{
  boost::property_tree::ptree pt;
  read_info(stream, pt);

  m_info.add_child(section.c_str(), pt);

  return *this;
}

void
InfoEditor::save(const std::string& fileName)
{
  std::ofstream output(fileName);
  write_info(output, m_info);
  output.close();
}

int
main(int argc, char** argv)
{
  std::string configFile;
  std::string sectionPath;
  std::string value;

  namespace po = boost::program_options;
  po::options_description description("Usage\n"
                                      "  infoedit [-f file] [-s|d|a|r path] [-v value]\n"
                                      "Options");

  description.add_options()
    ("help,h",    "print this help message")
    ("file,f",    po::value<std::string>(&configFile), "the file to edit")
    ("section,s", po::value<std::string>(&sectionPath), "the section to modify")
    ("path,p", po::value<std::string>(&sectionPath), "the path to add - can be duplicate")
    ("value,v",   po::value<std::string>(&value), "the value used to modify some section or add path")
    ("delete,d",  po::value<std::string>(&sectionPath), "the sub tree to delete")
    ("add,a",     po::value<std::string>(&sectionPath), "adds a sub tree")
    ("replace,r", po::value<std::string>(&sectionPath), "replace the sub tree")
    ;

  po::variables_map vm;
  try {
      po::store(po::command_line_parser(argc, argv).options(description).run(), vm);
      po::notify(vm);
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what()
              << "\n"
              << description;
    return 1;
  }

  if (vm.count("help") > 0) {
    std::cout << description;
    return 0;
  }

  if (vm.count("file") == 0) {
    std::cerr << "ERROR: the file to edit should be specified"
              << "\n"
              << description;
    return 1;
  }

  InfoEditor editor;
  try {
    editor.load(configFile);
  }
  catch (const std::exception& e) {
    std::cerr << "ERROR: " << e.what() << std::endl;
    return 1;
  }

  try {
    if (vm.count("section") > 0) {
      if (vm.count("value") == 0) {
        std::cerr << "ERROR: value must be specified" << std::endl;
        return 1;
      }

      editor.modify(sectionPath, value);
    }

    if (vm.count("path") > 0) {
      if (vm.count("value") == 0) {
        std::cerr << "ERROR: value must be specified" << std::endl;
        return 1;
      }

      editor.add(sectionPath, value);
    }

    if (vm.count("delete") > 0) {
      editor.remove(sectionPath);
    }

    if (vm.count("add") > 0) {
      editor.insert(sectionPath, std::cin);
    }

    if (vm.count("replace") > 0) {
      editor.remove(sectionPath).insert(sectionPath, std::cin);
    }
  }
  catch (...) {
    return 1;
  }

  try {
    editor.save(configFile);
  }
  catch (...) {
    std::cerr << "Unable to save the edit to file" << std::endl;
    return 1;
  }

  return 0;
}

} // namespace infoedit

int
main(int argc, char** argv)
{
  return infoedit::main(argc, argv);
}
