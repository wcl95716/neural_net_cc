
cmake_minimum_required(VERSION 3.19)
#库的名字
project(AD)

set(CMAKE_CXX_STANDARD 14)

#设置库
add_library(AD STATIC  ad_node.h ad_node.cpp)
#作用就是外面调用库不用加路径了
target_include_directories(AD PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )

#测试方法
add_executable(AD_test  ad_node.cpp)
#测试方法链接库
target_link_libraries(AD_test  AD gtest )

