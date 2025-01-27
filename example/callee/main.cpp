

#include "UserServices.h"
#include "mrpcApplication.hpp"
#include "rpcProvider.hpp"
#include "example.pb.h"

#define PROTOBUF_NAMESPACE_ID google::protobuf

int main(int argc, char **argv)
{

    // 初始化mrpc框架
    mrpcApplication *mrpc = mrpcApplication::getMrpcApplicationInstance();
    mrpc->Init(argc, argv);
    std::cout << mrpc->getConfigInfoString() << std::endl;

    // provider 是rpc服务提供者,把远程函数发布在rpc节点上
    rpcProvider provider;
    provider.NotifyService(new UserServices);
    provider.printServceInfo();
    provider.run();

    return 0;
}