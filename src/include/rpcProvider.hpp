#pragma once

//* 框架提供给用户使用的用于发布rpc service 的类

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include "mrpcApplication.hpp"
#include "google/protobuf/service.h"
#include "google/protobuf/descriptor.h"
#include <unordered_map>
#include "requestHeader.pb.h"

#define PROTOBUF_NAMESPACE_ID google::protobuf

class rpcProvider
{
private:
  muduo::net::EventLoop m_loop;

  void onConnection(const muduo::net::TcpConnectionPtr &conn);

  void onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp);
  void rpcClosure(muduo::net::TcpConnectionPtr conn, google::protobuf::Message *response) // callmethod 的收尾工作
                                                                                          // 序列化response并且发回调用端
  {

    std::string res_str;

    if (!response->SerializeToString(&res_str))
    {

      std::cout << "response反序列化失败" << std::endl;
      conn->shutdown();
      return;
    }

    conn->send(res_str);
  }

  struct serviceInfo
  {

    std::string m_serviceName;
    ::PROTOBUF_NAMESPACE_ID::Service *m_servicePtr;
    std::unordered_map<std::string, const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor *> m_methodMaps;
  };

  std::unordered_map<std::string, serviceInfo> m_servicesMaps;

public:
  void NotifyService(::PROTOBUF_NAMESPACE_ID::Service *);
  void printServceInfo();
  rpcProvider();

  // 启动rpc节点,开始提供rpc服务
  void run();

  ~rpcProvider();
};
