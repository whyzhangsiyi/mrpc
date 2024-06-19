



include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../protopb)


#设置源文件列表
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_CODE_LIST)

# 定义一个可执行文件及其源文件
add_executable(rpcProvider ${SOURCE_CODE_LIST}  ${CMAKE_CURRENT_SOURCE_DIR}/../protopb/example.pb.cc)

link_directories(/home/ziggy/repositories/mrpc/lib/libmrpc.so)

link_directories(/usr/local/lib)
                    
target_link_libraries(rpcProvider  protobuf  mrpc)


set_target_properties(rpcProvider PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
