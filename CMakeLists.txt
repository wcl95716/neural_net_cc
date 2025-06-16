cmake_minimum_required(VERSION 3.19)
project(neural_net_cc)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 14)

# 优先添加 googletest
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/packages/googletest")
    add_subdirectory(packages/googletest)
endif()

# 自动发现并添加所有包（排除 googletest）
file(GLOB PACKAGE_DIRS "packages/*")
foreach(PACKAGE_DIR ${PACKAGE_DIRS})
    if(IS_DIRECTORY ${PACKAGE_DIR})
        get_filename_component(PACKAGE_NAME ${PACKAGE_DIR} NAME)
        if(NOT ${PACKAGE_NAME} STREQUAL "googletest")
            add_subdirectory(${PACKAGE_DIR})
            # 自动添加包的包含路径
            include_directories(${PACKAGE_DIR}/include)
            # 收集所有包名
            list(APPEND ALL_PACKAGES ${PACKAGE_NAME})
        endif()
    endif()
endforeach()

# 设置全局变量，让子项目可以使用
set(ALL_PACKAGES ${ALL_PACKAGES} PARENT_SCOPE)

# 添加 src 目录
add_subdirectory(src) 