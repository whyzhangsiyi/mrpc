#pragma once

//* 框架提供给用户使用的用于发布rpc service 的类

#include "google/protobuf/service.h"

#define PROTOBUF_NAMESPACE_ID google::protobuf

class rpcProvider
{
private:
  /* data */
public:
  rpcProvider(/* args */);

  void NotifyService(::PROTOBUF_NAMESPACE_ID::Service *);

  // 启动rpc节点,开始提供rpc服务
  void run();

  ~rpcProvider();
};

