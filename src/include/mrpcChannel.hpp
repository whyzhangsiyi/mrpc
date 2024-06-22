#pragma once

#include "google/protobuf/service.h"
#include "requestHeader.pb.h"
#include "muduo/net/TcpClient.h"
#include "mrpcApplication.hpp"
#include "muduo/net/EventLoop.h"
#include "google/protobuf/message.h"

class mrpcChannel : public google::protobuf::RpcChannel
{
private:
public:
  // 重写RpcChannel的纯虚函数
  void
  CallMethod(const ::google::protobuf::MethodDescriptor *method,
             ::google::protobuf::RpcController *controller, const ::google::protobuf::Message *request,
             ::google::protobuf::Message *response, ::google::protobuf::Closure *done) override
  {

    const ::google::protobuf::ServiceDescriptor *s_desc = method->service();

    // 封装请求头
    header::requestHeader _header;
    _header.set_service_name(s_desc->name());
    _header.set_method_name(method->name());
    // request->SerializeToString(&args_str);
    _header.set_args(request->SerializeAsString());
    // 封装字节数是必要的
    // int head_len =_header.service_name().size() + _header.method_name().size() + _header.args().size();

    // 请求封装完毕,通过网络发送该请求
    mrpcApplication *app = mrpcApplication::getMrpcApplicationInstance();

    std::string server_ip = app->getConfigItem("mrpcserver_ip");
    std::string server_port = app->getConfigItem("mrpcserver_port");
    std::string channnelName = method->service()->name() + "_Channel";
    muduo::net::InetAddress rpcserver_addr(server_ip, std::stoi(server_port));

    muduo::net::EventLoop _loop;

    muduo::net::TcpClient _client(&_loop, rpcserver_addr, channnelName);
    _client.setConnectionCallback([_header](const muduo::net::TcpConnectionPtr &conn) // 连接成功时发送rpc请求
                                  {

                                    if (!conn->connected())
                                    {
                                      conn->shutdown();
                                      conn->getLoop()->quit();
                                   }
                                    
                                    // std::string _header_srt;
                                    // _header.SerializeToString(&_header_srt);
                                    // int header_len=_header_srt.length();
                                    // _header_srt.insert(0,std::string(((char*)&header_len),4));
                                    // std::cout << "_header_srt: " << _header_srt << std::endl;

                                    //先不考虑粘包问题

                                    conn->send(_header.SerializeAsString()); });

    _client.setMessageCallback([response](const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf, muduo::Timestamp tmp)
                               {
                                 std::string response_rec = buf->retrieveAllAsString();
                                 if (!response->ParseFromString(response_rec))
                                 {
                                   std::cout << "rpc响应序列化失败" << std::endl;
                                 }
                                 // 响应序列化成功,该次rpc调用完成,关闭loop,关闭客户端连接

                                 conn->getLoop()->quit(); });

    _client.connect();
    _loop.loop();
  }

  // 在channel实例内构造一个tcpclient用作网络的收发层
  // tcpclient构造函数需要的参数

  mrpcChannel();

  ~mrpcChannel();
};

mrpcChannel::mrpcChannel() {}

mrpcChannel::~mrpcChannel()
{
}
