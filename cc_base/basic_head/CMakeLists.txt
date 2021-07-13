
cmake_minimum_required(VERSION 3.19)
#库的名字
project(basic_head)

set(CMAKE_CXX_STANDARD 14)

#设置库
add_library(basic_head STATIC  basic_head.h basic_head.cpp)
#作用就是外面调用库不用加路径了
target_include_directories(basic_head PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

#测试方法
add_executable(test_basic_heap test/test_basic_heap.cpp)
#测试方法链接库
target_link_libraries(test_basic_heap  basic_head gtest )

