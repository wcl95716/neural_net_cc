# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)

# 获取项目名并设置
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

#===========================================
# 库的创建部分
#===========================================
add_library(${PROJECT_NAME} STATIC lib.h lib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#===========================================
# 测试部分
#===========================================
# 设置 googletest 路径
get_filename_component(GTEST_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../external/googletest" ABSOLUTE)
add_subdirectory(${GTEST_ROOT} ${CMAKE_CURRENT_BINARY_DIR}/googletest)

add_executable(${PROJECT_NAME}_test test/test_lib.cpp)
target_include_directories(${PROJECT_NAME}_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}_test ${PROJECT_NAME} gtest gtest_main)
