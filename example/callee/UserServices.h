
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../protopb/example.pb.h"

class UserServices : public example::UserServicesRpc // 使用在rpc的发布端
{
public:
    UserServices(/* args */) {}
    virtual ~UserServices() {}

    bool
    Login(std::string name, std::string password) // 本地的login方法,要发布成rpc方法
    {
        std::cout << "login called" << std::endl;
        return true;
    }

    bool getFriendList(int32_t userid, std::vector<example::user> &friendlist)
    {
        std::cout << "do some database access and get friend list" << std::endl;
    }

    //*重写父类 UserServicesRpc的虚函数,即是本地方法的rpc "形式",用户重写的方法给rpc框架调用

    // 工作原理
    //*     1.框架给业务上报了函数参数(LoginRequest),(通过网络)
    //*     2.用户拿着参数调用本地方法
    //*     3.再封装响应(LoginResponse)
    //*     4.最后给框架发射done信号通知框架本地方法调用完成,给caller返回结果 (通过网络)

    void Login(::google::protobuf::RpcController *controller, // 真正被调用的rpc方法
               const ::example::LoginRequest *request,
               ::example::LoginResponse *response,
               ::google::protobuf::Closure *done) override
    {

        if (Login(request->name(), request->pwd()))
        {
            response->set_success(true);
            example::errorInfo *errinfo = response->mutable_errinfo();
            errinfo->set_errcode(example::errorInfo::NOERROR);
            errinfo->set_errmsg("success");
        }
        else
        {

            response->set_success(false);
            example::errorInfo *errinfo = response->mutable_errinfo();
            errinfo->set_errcode(example::errorInfo::NOSUCHUSERID);
            errinfo->set_errmsg("invalid password");
        }

        done->Run();
    }

    void getFriendList(::google::protobuf::RpcController *controller,
                       const ::example::getFriendListRequest *request,
                       ::example::getFriendListResponse *response,
                       ::google::protobuf::Closure *done) override
    {
        std::vector<example::user> friendList;

        if (getFriendList(request->userid(), friendList))
        {
            example::errorInfo *errinfo = response->mutable_errinfo();
            errinfo->set_errcode(example::errorInfo::NOERROR);
            errinfo->set_errmsg("no error");
            for (size_t i = 0; i < friendList.size(); i++)
            {
                example::user *hisfriend = response->add_friendlist();
                hisfriend->set_name(friendList[i].name());
                hisfriend->set_age(friendList[i].age());
                hisfriend->set_sex(friendList[i].sex());
            }
        }
        else
        {
            example::errorInfo *errinfo = response->mutable_errinfo();
            errinfo->set_errcode(example::errorInfo::NOSUCHUSERID);
            errinfo->set_errmsg("no such userid ");
        }

        done->Run();
    }
};