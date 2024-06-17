#include "test.pb.h"
#include <iostream>
#include<string>




int main(){

//对象数据序列化成字符串
testProto::LoginRequest logreq;
logreq.set_name("张三");
logreq.set_pwd("123456");
std::string send_str;

if (logreq.SerializeToString(&send_str))
{
    std::cout<<send_str<<std::endl;
}


//从send_str反序列化成loginRequest对象

testProto::LoginRequest logreq2;
if (logreq2.ParseFromString(send_str)){

    std::cout<<logreq2.name()<<"    ";
    std::cout<<logreq2.pwd()<<std::endl;
}




testProto::getFriendList friendListResponse;
testProto::errorInfo *errinfo = friendListResponse.mutable_errinfo();
errinfo->set_errcode(testProto::errorInfo::NOERROR);
errinfo->set_errmsg("no error");



for (size_t i = 0; i < 20; i++)
{
    testProto::user *us = friendListResponse.add_friendlist();
    us->set_name("张三");
    us->set_age(10+i);
    // us->set_sex(testProto::user::MAN);
}

    // std::string friendList_str;
    // friendListResponse.SerializeToString(&friendList_str);
    // std::cout<<"friend count: "<<friendListResponse.friendlist_size()<<std::endl;
    // std::cout<<friendList_str<<std::endl;

testProto::user us;
us.set_name("张三");
us.set_age(10);
us.set_sex(testProto::user::WOMAN);



std::string user_str;
us.SerializeToString(&user_str);
std::cout<<user_str<<std::endl;
testProto::user us2;
us2.ParseFromString(user_str);
std::cout << us2.name();
std::cout << us2.age();
std::cout<<us2.sex();
// std::cout<<user_str<<"**"<<std::endl;
}