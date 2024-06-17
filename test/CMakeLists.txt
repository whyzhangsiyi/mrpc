# 设置最低的CMake版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称
project(MyProject VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加源文件
set(SOURCES
    ./main.cpp
    ./test.pb.cc
)

# 添加头文件目录
include_directories(./)

# 添加可执行文件
add_executable(MyProject ${SOURCES})

target_link_libraries(MyProject protobuf)         #链接protobuf库