# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)

# 获取包名
get_filename_component(PACKAGE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PACKAGE_NAME})

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 创建库
add_library(${PACKAGE_NAME} STATIC 
    src/core/base.cpp
)

# 设置包含目录
target_include_directories(${PACKAGE_NAME}
    INTERFACE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include/public  # 对外暴露 public 目录
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/include/private  # 内部头文件对库本身可见
)

# 创建测试
enable_testing()
add_executable(${PACKAGE_NAME}_test test/test_lib.cpp)
target_include_directories(${PACKAGE_NAME}_test PRIVATE include)
target_link_libraries(${PACKAGE_NAME}_test
    PRIVATE
        gtest
        gtest_main
        pthread
        ${PACKAGE_NAME}
)
add_test(NAME ${PACKAGE_NAME}_test COMMAND ${PACKAGE_NAME}_test)


# 平台特定设置
if(WIN32)
    target_link_libraries(${PACKAGE_NAME}_test ws2_32)
endif()
