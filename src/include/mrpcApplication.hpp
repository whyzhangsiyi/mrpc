
#pragma once
#include "mrpcConfig.hpp"
#include <string>
class mrpcApplication
{

private:
  mrpcConfig m_config;
  bool _inited;

private:
  mrpcApplication();
  mrpcApplication(const mrpcApplication &) = delete;
  mrpcApplication(mrpcApplication &&) = delete;

public:
  ~mrpcApplication();

  bool isInit()
  {

    return _inited;
  }

  std::string getConfigItem(std::string key)
  {
    if (_inited)
    {
      return m_config.getConfigItem(key);
    }
  }

  std::string getConfigInfoString()
  {

    if (_inited)
    {
      return m_config.getConfigInfoString();
    }
  }

  std::string getConfigFilePath()
  {

    if (_inited)
    {
      return m_config.getConfigFilePath();
    }
  }

  static mrpcApplication *getMrpcApplicationInstance();

  void Init(int argc, char **argv);
};
