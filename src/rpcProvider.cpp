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

void rpcProvider::onConnection(const muduo::net::TcpConnectionPtr &conn)
{ // 新连接回调

  if (!conn->connected())
  {
    conn->shutdown();
  }
}

void rpcProvider::onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp tsp)
{

  // rpc请求到来,做序列化与反序列化,框架实质上的大部分工作在此完成

  //* 反序列化请求头,获取远程调用的信息
  std::string rec_str = buffer->retrieveAllAsString();
  header::requestHeader headerinfo;
  int headerLen;
  rec_str.copy((char *)&headerLen, 4, 0);

  if (!headerinfo.ParseFromString(rec_str.substr(0, headerLen))) // 序列化一个请求头对象
  {
    std::cout << "请求头对象序列化失败,rpc请求格式错误" << std::endl;
    conn->shutdown();
    return;
  }

  //* 查询远程调用是否存在,该远程调用是否正确
  auto s_it = m_servicesMaps.find(headerinfo.service_name());
  if (s_it == m_servicesMaps.end())
  {
    std::cout << "请求的service不存在!" << std::endl;
    conn->shutdown();
    return;
  }

  auto m_it = s_it->second.m_methodMaps.find(headerinfo.method_name());

  if (m_it == s_it->second.m_methodMaps.end())
  {
    std::cout << "请求的远程方法不存在!" << std::endl;
    conn->shutdown();
    return;
  }

  // 服务名,方法名都存在,即该远程调用有效,以下是封装请求,进行调用,和封装返回值的代码

  // 拿到该服务的指针(通过该指针调用其方法)
  ::google::protobuf::Service *_service = s_it->second.m_servicePtr;
  const ::google::protobuf::MethodDescriptor *m_desc = m_it->second; // 拿到该方法的描述符,以备调用

  // 封装请求

  ::google::protobuf ::Message *request = _service->GetRequestPrototype(m_desc).New();   // 请求类型
  ::google::protobuf ::Message *response = _service->GetResponsePrototype(m_desc).New(); // 响应类型

  if (request->ParseFromString(headerinfo.args())) // 反序列化请求
  {

    std::cout << "远程调用参数反序列化失败" << std::endl;
    conn->shutdown();
    return;
  }

  google::protobuf::Closure *done = google::protobuf::NewCallback(this, &rpcProvider::rpcClosure, conn, response);

  _service->CallMethod(m_desc, nullptr, request, response, done);

  conn->shutdown(); // 短连接,服务完主动断开
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

void rpcProvider::printServceInfo()
{

  for (const auto &i : m_servicesMaps)
  {

    std::cout << "service name: " << i.first << std::endl;
    std::cout << "method:   ";

    for (const auto &k : i.second.m_methodMaps)
    {

      std::cout << k.first << "  ";
    }
    std::cout << std::endl;
  }
}

rpcProvider::rpcProvider(/* args */)
{
}

rpcProvider::~rpcProvider()
{
}
