#pragma once

//* 框架提供给用户使用的用于发布rpc service 的类

#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include "mrpcApplication.hpp"
#include "google/protobuf/service.h"

#define PROTOBUF_NAMESPACE_ID google::protobuf

class rpcProvider
{
private:
  muduo::net::EventLoop m_loop;
  void onConnection(const muduo::net::TcpConnectionPtr &conn) {}
  void onMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *, muduo::Timestamp) {}

public:
  void NotifyService(::PROTOBUF_NAMESPACE_ID::Service *);
  rpcProvider();

  // 启动rpc节点,开始提供rpc服务
  void run();

  ~rpcProvider();
};
