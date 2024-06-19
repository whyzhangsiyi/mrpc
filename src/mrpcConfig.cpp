
#include "mrpcConfig.hpp"

mrpcConfig::mrpcConfig(/* args */) {}
mrpcConfig::~mrpcConfig() {}
std::string mrpcConfig::getConfigFilePath() { return m_configFilePath; }
const std::unordered_map<std::string, std::string> &mrpcConfig::getConfigMap()
{
  return m_configItems;
}

void mrpcConfig::load(int argc, char **argv)
{
  loadConfigFilePath(argc, argv);
  loadConfigItems();
}

void mrpcConfig::loadConfigFilePath(int argc, char **argv)
{

  if (argc < 2)
  {
    std::cout << "服务器启动失败,请检查启动参数" << std::endl;
    std::cout << "fomat: " << "command  -i <configFilePath>" << std::endl;
    exit(EXIT_FAILURE);
  }

  char opt;
  while ((opt = getopt(argc, argv, "i:")) != -1)
  {
    switch (opt)
    {
    case 'i':
      m_configFilePath = std::string(optarg);
      break;
    default:
      break;
    }
  }
}

void mrpcConfig::loadConfigItems()
{

  // FILE *configfile = fopen(m_configFilePath.c_str(), "r");

  std::ifstream configfile(m_configFilePath);

  if (!configfile.is_open())
  {
    std::cout << "  config file (" << m_configFilePath << ") is invalid, progress existed " << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  while (std::getline(configfile, line))
  {
    if (line[0] == '#' || line.empty()) // 跳过注释项和空行
    {
      continue;
    }

    if (line.find('=', 0) == std::string::npos)
    {
      continue; // 跳过无效配置项目
    }

    removeSpace(line);

    int pos = line.find('=', 0);

    std::string configkey = line.substr(0, pos); // 范围是前闭后开区间
    std::string configval = line.substr(pos + 1, line.size());
    m_configItems.insert({configkey, configval}); // 封装配置项的键值,加入map表以备使用
  }
}

int mrpcConfig::removeSpace(std::string &line)
{
  int counter = 0;
  int pos = -1;
  while ((pos = line.find(' ', 0)) != std::string::npos)
  {
    counter++;
    line.erase(pos);
  }
  return counter; // 返回被删除的空格个数
}

std::string mrpcConfig::getConfigItem(const std::string &key)
{

  auto it = m_configItems.find(key);
  if (it == m_configItems.end())
  {
    return std::string();
  }
  else
  {
    return it->second;
  }
}

std::string mrpcConfig::getConfigInfoString()
{
  std::string info;
  info.append("**********CONFIG INFO**********\n");

  info.append("config file path: ");
  info.append(m_configFilePath);
  info.append("\n");

  for (auto i : m_configItems)
  {
    std::string item;
    item.append(i.first + " = ");
    item.append(i.second);
    item.append("\n");
    info.append(item);
  }
  info.append("**********CONFIG INFO**********\n");
  return info;
}
