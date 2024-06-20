# 设置变量的值
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
#设置可执行文件输出路径
#设置头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
link_directories(/usr/local/lib)


#设置源文件列表
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_CODE_LIST)

add_library(mrpc  ${SOURCE_CODE_LIST})             # 不带SHARED则默认编译成静态库

#muduo默认编译生成了静态库,如果该rpc框架生成动态库的话就会存在动态库连接静态库的问题
#解决办法: 把muduo编译成动态库或者本框架编译成静态库,只要库类型一致即可


target_link_libraries(mrpc  muduo_net  muduo_base   pthread)


#设置输出的目标的属性
set_target_properties(mrpc PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

