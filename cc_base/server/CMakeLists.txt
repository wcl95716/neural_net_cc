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

# 将工程目录添加到target_include_directories  这样可以方便引用其它文件的库
get_filename_component(Root_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)

# 添加上上层目录到包含目录

target_include_directories(${project_test_name} PRIVATE ${Root_DIR})
target_include_directories(${project_name} PRIVATE ${Root_DIR})

# 将工程目录添加到target_include_directories  这样可以方便引用其它文件的库
get_filename_component(UP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/.." ABSOLUTE)

# 添加上上层目录到包含目录
target_include_directories(${project_test_name} PUBLIC  ${UP_DIR})
target_include_directories(${project_name} PUBLIC  ${UP_DIR})

#测试方法链接库
target_link_libraries(${project_test_name}  ${project_name} gtest  basic_head server )

if(APPLE)
    # macOS 相关设置
elseif(WIN32)
    # Windows 相关设置
    target_link_libraries(${project_test_name}  ${project_name} ws2_32)
endif()
