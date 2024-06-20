
#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <unistd.h>

extern "C" char *optarg;

class mrpcConfig
{

private:
  std::string m_configFilePath;
  std::unordered_map<std::string, std::string> m_configItems;

public:
  mrpcConfig(/* args */);
  ~mrpcConfig();
  std::string getConfigFilePath();
  const std::unordered_map<std::string, std::string> &getConfigMap();

  std::string getConfigItem(const std::string &key);
  std::string getConfigInfoString();

  void load(int argc, char **argv);

private:
  void loadConfigFilePath(int argc, char **argv);
  void loadConfigItems();

  int removeSpace(std::string &line);
};
