



#设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

#设置库文件输出路径
set(LIBRARY_OUTPUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/lib)

#设置头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src)

# 定义一个可执行文件及其源文件
add_executable(MyExecutable main.cpp)

add_subdirectory(src)
add_subdirectory(example)