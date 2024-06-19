# 设置变量的值
set(CMAKE_CXX_STANDARD 11)

#设置可执行文件输出路径
#设置头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#设置源文件列表
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCE_CODE_LIST)

add_library(mrpc  SHARED ${SOURCE_CODE_LIST})



#设置输出的目标的属性
set_target_properties(mrpc PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)

