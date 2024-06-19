#include "mrpcApplication.hpp"
mrpcApplication *mrpcApplication::getMrpcApplicationInstance()
{
  static mrpcApplication *mrpcApp_ptr = new mrpcApplication();
  return mrpcApp_ptr;
}

void mrpcApplication::Init(int argc, char **argv)
{

  // 读取配置文件,为框架的初始化,配置和使用做工作
}

mrpcApplication::mrpcApplication(/* args */)
{
}

mrpcApplication::~mrpcApplication()
{
}
