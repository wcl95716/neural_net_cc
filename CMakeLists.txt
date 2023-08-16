
cmake_minimum_required(VERSION 3.19)
project(test_cc_pro)

set(CMAKE_CXX_STANDARD 14)

# 将目录种所有库添加
#add_subdirectory(cc_base)
#add_subdirectory(src_template)

file(GLOB SUBDIRECTORIES "./*")

foreach(subdir ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${subdir})
        get_filename_component(dirname ${subdir} NAME)

        string(FIND ${dirname} "build" _build_found)
        if(
                NOT ${dirname} MATCHES "build|\\.|git"
        )
            add_subdirectory(${dirname})
        endif()
    endif()
endforeach()


#批量引用库
SET(EXTERNAL_LIB
        gtest
        )


#file(GLOB SUBDIRECTORIES "./cc_base/*")
#
#foreach(subdir ${SUBDIRECTORIES})
#    if(IS_DIRECTORY ${subdir})
#        get_filename_component(dirname ${subdir} NAME)
#        message("dirname " ${dirname})
#        if(
#                NOT ${dirname} STREQUAL "googletest" AND
#                NOT ${dirname} STREQUAL "cpp-httplib"
#        )
#            list(APPEND EXTERNAL_LIB ${dirname})
#        endif()
#    endif()
#endforeach()


file(GLOB SUBDIRECTORIES "./*")
foreach(subdir ${SUBDIRECTORIES})
    # 获取子文件夹的名字
    get_filename_component(dirname ${subdir} NAME)
    # 判断当前是否是文件夹
    # 如果文件夹包含 build . 和git  就跳过
    # build 一般是cmake 的build 文件夹  . 一般为.idea and .vscode
    if(NOT IS_DIRECTORY ${subdir} OR
            ${dirname} MATCHES "build|\\.|git"
    )
        CONTINUE()
    endif()
    file(GLOB SON_SUBDIRECTORIES "./${dirname}/*")
    foreach(subdir ${SON_SUBDIRECTORIES})
        if(IS_DIRECTORY ${subdir})
            get_filename_component(dirname ${subdir} NAME)
            if(
                    NOT ${dirname} STREQUAL "googletest" AND
                    NOT ${dirname} STREQUAL "cpp-httplib"
            )
                list(APPEND EXTERNAL_LIB ${dirname})
            endif()
        endif()
    endforeach()
    message("subdir:" ${subdir})
endforeach()

# 使用message输出列表内容
message("EXTERNAL_LIB contains:")
foreach(lib ${EXTERNAL_LIB})
    message(" - ${lib}")
endforeach()

#测试方法
add_executable(test_cc_pro main.cpp)

# 将cc_base 引用提一层
#target_include_directories(test_cc_pro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cc_base )
#target_include_directories(test_cc_pro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )
target_include_directories(test_cc_pro INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/ )

message("root : " ${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries(test_cc_pro  ${EXTERNAL_LIB}  )


