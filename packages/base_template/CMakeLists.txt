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
    PUBLIC include
    PRIVATE src
)

# 创建测试
add_executable(${PACKAGE_NAME}_test test/test_lib.cpp)

# 设置测试的包含目录
target_include_directories(${PACKAGE_NAME}_test PRIVATE include)

# 链接依赖
target_link_libraries(${PACKAGE_NAME} server)
target_link_libraries(${PACKAGE_NAME}_test ${PACKAGE_NAME} gtest basic_custom_heap server)

# 平台特定设置
if(WIN32)
    target_link_libraries(${PACKAGE_NAME}_test ws2_32)
endif()
