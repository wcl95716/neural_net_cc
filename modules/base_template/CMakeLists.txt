# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)

# 获取项目名并设置
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 创建库和测试
add_library(${PROJECT_NAME} STATIC lib.h lib.cpp)
add_executable(${PROJECT_NAME}_test test/test_lib.cpp)

# 设置包含目录
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME}_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 链接库
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} gtest)

# 平台特定配置
if(WIN32)
    target_link_libraries(${PROJECT_NAME}_test ws2_32)
endif()
