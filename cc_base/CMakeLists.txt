# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
project(cc_base)

set(CMAKE_CXX_STANDARD 14)

#add_subdirectory(basic_head)
#add_subdirectory(googletest)
#add_subdirectory(automatic_differentiation)
#add_subdirectory(test1)

#获取当前目录下的所有子目录路径
file(GLOB subdirectories LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/*)

# 遍历子目录并添加为子项目
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory})
        #message("subdirectory " ${subdirectory})
        get_filename_component(subdir_name ${subdirectory} NAME)
        message("subdir_name " ${subdir_name})
        add_subdirectory(${subdirectory} ${CMAKE_BINARY_DIR}/${subdir_name})
    endif()
endforeach()
