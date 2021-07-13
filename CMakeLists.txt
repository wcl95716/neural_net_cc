cmake_minimum_required(VERSION 3.19)
project(test_cc_pro)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cc_base)


#批量引用库
SET(EXTERNAL_LIB
        basic_head
        gtest
        AD
        AD2
        )

#测试方法
add_executable(test_cc_pro main.cpp)

target_link_libraries(test_cc_pro  ${EXTERNAL_LIB}  )


