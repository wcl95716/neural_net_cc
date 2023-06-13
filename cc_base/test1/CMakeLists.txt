# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
# 获取当前文件夹名
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(project_name  ${PROJECT_NAME})
set(project_test_name  ${PROJECT_NAME}_test)
#message("PROJECT_NAME: ${PROJECT_NAME}")
#message("project_name: ${project_name}")
#message("project_test_name: ${project_test_name}")
# 设置项目名称
project(${project_name})

set(CMAKE_CXX_STANDARD 14)

#设置库
add_library(${project_name} STATIC lib.h lib.cpp)

#测试方法
add_executable(${project_name}_test test/test_lib.cpp)

# 设置上上层目录的路径
get_filename_component(UPUP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../" ABSOLUTE)
message("UPUP_DIR" , ${UPUP_DIR})
# 添加上上层目录到包含目录
target_include_directories(${project_test_name} PRIVATE ${UPUP_DIR})
target_include_directories(${project_name} PRIVATE ${UPUP_DIR})

#测试方法链接库
target_link_libraries(${project_test_name}  ${project_name} gtest )


