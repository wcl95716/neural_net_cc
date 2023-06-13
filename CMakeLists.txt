cmake_minimum_required(VERSION 3.19)
project(test_cc_pro)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cc_base)

#批量引用库
SET(EXTERNAL_LIB
        gtest
        )


file(GLOB SUBDIRECTORIES "./cc_base/*")

foreach(subdir ${SUBDIRECTORIES})
    if(IS_DIRECTORY ${subdir})
        get_filename_component(dirname ${subdir} NAME)
        message("dirname " ${dirname})
        if(NOT ${dirname} STREQUAL "googletest")
            list(APPEND EXTERNAL_LIB ${dirname})
        endif()
    endif()
endforeach()
message("EXTERNAL_LIB " ${EXTERNAL_LIB})



#测试方法
add_executable(test_cc_pro main.cpp)

# 将cc_base 引用提一层
target_include_directories(test_cc_pro PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/cc_base )

message(${CMAKE_CURRENT_SOURCE_DIR} )

target_link_libraries(test_cc_pro  ${EXTERNAL_LIB}  )


