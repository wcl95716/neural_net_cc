# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(project_name  ${PROJECT_NAME})
project(project_name)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD 14)



#获取当前目录下的所有子目录路径
file(GLOB subdirectories LIST_DIRECTORIES true ${CMAKE_CURRENT_SOURCE_DIR}/*)

# 遍历子目录并添加为子项目
foreach(subdirectory ${subdirectories})
    if(IS_DIRECTORY ${subdirectory}
            # 如果下载grpc 注释此行
            AND NOT ${subdirectory} MATCHES "grpc_service"
        )
        message("subdirectory " ${subdirectory})
        get_filename_component(subdir_name ${subdirectory} NAME)
        add_subdirectory(${subdirectory}  )
        # 获取子文件夹中的项目名
        get_directory_property(SUBFOLDER_PROJECT_NAME DIRECTORY ${subdirectory} DEFINITION PROJECT_NAME)
        message("子文件夹的项目名是: ${SUBFOLDER_PROJECT_NAME}")

    endif()
endforeach()



