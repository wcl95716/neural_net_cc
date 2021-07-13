cmake_minimum_required(VERSION 3.19)
#库的名字
project(cc_base)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(basic_head)
add_subdirectory(googletest)
add_subdirectory(automatic_differentiation)
add_subdirectory(automatic_diff)
