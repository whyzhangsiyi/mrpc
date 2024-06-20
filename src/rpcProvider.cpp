#include "rpcProvider.hpp"

// 启动rpc节点,开始提供rpc服务

void rpcProvider::NotifyService(::PROTOBUF_NAMESPACE_ID::Service *service)
{

  serviceInfo serviceinfo;
  serviceinfo.m_servicePtr = service;

  const ::google::protobuf::ServiceDescriptor *s_desc = service->GetDescriptor();
  serviceinfo.m_serviceName = s_desc->name();
  int methodcnt = s_desc->method_count(); // 该方法返回该service类内定义的(远程)方法的个数

  for (size_t i = 0; i < methodcnt; i++)
  {
    const ::google::protobuf::MethodDescriptor *m_desc = s_desc->method(i); // 描述符必须为const,不然可能造成映射信息错误
    serviceinfo.m_methodMaps.insert({m_desc->name(), m_desc});
  }

  m_servicesMaps.insert({s_desc->name(), serviceinfo});
}

void rpcProvider ::run()
{
  // 读取配置文件里的配置数据
  std::string ip = mrpcApplication::getMrpcApplicationInstance()->getConfigItem("mrpcserver_ip");
  int port = std::stoi(mrpcApplication::getMrpcApplicationInstance()->getConfigItem("mrpcserver_port"));

  muduo::net::InetAddress addr(ip, port);

  // 创建rpc服务器对象
  muduo::net::TcpServer _server(&m_loop, addr, "rpcProvider");

  // 为服务器绑定连接回调和读写回调
  _server.setConnectionCallback(std::bind(&rpcProvider::onConnection, this, std::placeholders::_1));
  _server.setMessageCallback(std::bind(&rpcProvider::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  // 设置线程数量
  _server.setThreadNum(4);

  // 启动服务器,进入事件循环
  _server.start();
  m_loop.loop();
}

rpcProvider::rpcProvider(/* args */)
{
}

rpcProvider::~rpcProvider()
{
}
