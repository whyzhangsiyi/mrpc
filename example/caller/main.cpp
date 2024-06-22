#include "mrpcChannel.hpp"
#include "example.pb.h"
#include "mrpcApplication.hpp"
#include <string>
#include "muduo/net/InetAddress.h"

int main(int argc, char **argv)
{

  mrpcApplication *app = mrpcApplication::getMrpcApplicationInstance();
  app->Init(argc, argv);

  mrpcChannel useServiceChannle;
  example::UserServicesRpc_Stub userService_stub(&useServiceChannle);

  example::LoginRequest req;
  example::LoginResponse resp;
  req.set_name("张三");
  req.set_pwd("12345");
  std::cout << req.SerializeAsString() << std::endl;
  std::string test;
  req.SerializeToString(&test);
  std::cout << test << std::endl;

  userService_stub.Login(nullptr, &req, &resp, nullptr);

  std::cout << "***********rpc response*************" << std::endl;
  std::cout << "errorcode " << resp.errinfo().errcode() << std::endl;
  std::cout << "errormsg " << resp.errinfo().errmsg() << std::endl;
  std::cout << "if success " << resp.success() << std::endl;

  std::cout << "***********rpc response*************" << std::endl;

  return 0;
}