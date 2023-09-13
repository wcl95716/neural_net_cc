# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
set(ABSL_ENABLE_INSTALL ON)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(project_name  ${PROJECT_NAME})
project(project_name)
set(CMAKE_CXX_STANDARD 14)

#获取当前目录下的所有子目录路径
file(GLOB subdirectories LIST_DIRECTORIES true
        ${CMAKE_CURRENT_SOURCE_DIR}/*
        # ${CMAKE_CURRENT_SOURCE_DIR}/../../cc_base
)

# 遍历子目录并添加为子项目
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory}
           # AND NOT ${subdirectory} MATCHES "grpc"
    )
        #message("subdirectory " ${subdirectory})
        get_filename_component(subdir_name ${subdirectory} NAME)
        add_subdirectory(${subdirectory} ${CMAKE_BINARY_DIR}/${subdir_name})
    endif()
endforeach()


