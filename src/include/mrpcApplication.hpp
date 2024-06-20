
#pragma once
#include "mrpcConfig.hpp"
#include <string>
class mrpcApplication
{

private:
  mrpcConfig m_config;

private:
  mrpcApplication();
  mrpcApplication(const mrpcApplication &) = delete;
  mrpcApplication(mrpcApplication &&) = delete;

public:
  ~mrpcApplication();

  std::string getConfigItem(std::string key)
  {

    return m_config.getConfigItem(key);
  }

  std::string getConfigInfoString()
  {

    return m_config.getConfigInfoString();
  }

  std::string getConfigFilePath()
  {
    return m_config.getConfigFilePath();
  }

  static mrpcApplication *getMrpcApplicationInstance();

  void Init(int argc, char **argv);
};
