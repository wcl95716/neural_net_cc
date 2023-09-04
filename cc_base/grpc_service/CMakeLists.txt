# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
# 获取当前文件夹名
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(project_name  ${PROJECT_NAME})
set(project_test_name  ${PROJECT_NAME}_test)
#message("PROJECT_NAME: ${PROJECT_NAME}")
#message("project_name: ${project_name}")
#message("project_test_name: ${project_test_name}")
# 设置项目名称
project(${project_name})

set(CMAKE_CXX_STANDARD 14)

#设置库
add_library(${project_name} STATIC lib.h lib.cpp)

#测试方法
add_executable(${project_name}_test test/test_lib.cpp)

# 将工程目录添加到target_include_directories  这样可以方便引用其它文件的库
get_filename_component(Root_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)

# 添加上上层目录到包含目录

target_include_directories(${project_test_name} PRIVATE ${Root_DIR})
target_include_directories(${project_name} PRIVATE ${Root_DIR})


# Set _WIN32_WINNT value to 0x600 to support Windows Vista and later
add_definitions(-D_WIN32_WINNT=0x600)

# 添加grpc子模块
# set(ABSL_ENABLE_INSTALL ON)

include(FetchContent)

set(ABSL_ENABLE_INSTALL ON)
FetchContent_Declare(
        absl
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG        origin/master
        OVERRIDE_FIND_PACKAGE
)
FetchContent_MakeAvailable(absl)

FetchContent_Declare(
        gRPC
        GIT_REPOSITORY https://github.com/grpc/grpc
        GIT_TAG        v1.48.0
)
set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(gRPC)




# Define your proto files
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protos)
message("CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})
message("PROTO_SRC_DIR " ${PROTO_SRC_DIR})
set(PROTO_FILES
        ${PROTO_SRC_DIR}/proto_file.proto
)

# Compile your proto files
foreach(PROTO_FILE ${PROTO_FILES})
    get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
    message("PROTO_NAME " ${PROTO_NAME})
    get_filename_component(ABS_PROTO ${PROTO_FILE} ABSOLUTE)
    set(PROTO_SRC ${CMAKE_BINARY_DIR}/${PROTO_NAME}.pb.cc)
    message("CMAKE_BINARY_DIR " ${CMAKE_BINARY_DIR})
    set(PROTO_HDR ${CMAKE_BINARY_DIR}/${PROTO_NAME}.pb.h)
    set(GRPC_SRC ${CMAKE_BINARY_DIR}/${PROTO_NAME}.grpc.pb.cc)
    set(GRPC_HDR ${CMAKE_BINARY_DIR}/${PROTO_NAME}.grpc.pb.h)
    add_custom_command(
            OUTPUT "${PROTO_SRC}" "${PROTO_HDR}" "${GRPC_SRC}" "${GRPC_HDR}"
            COMMAND protobuf::protoc
            ARGS --grpc_out "${CMAKE_BINARY_DIR}"
            --cpp_out "${CMAKE_BINARY_DIR}"
            -I "${PROTO_SRC_DIR}"
            --plugin=protoc-gen-grpc="${_gRPC_PROTOC_GRPCPP_PLUGIN_EXECUTABLE}"
            "${ABS_PROTO}"
            DEPENDS "${ABS_PROTO}")
endforeach()


#测试方法链接库
target_link_libraries(${project_test_name}
        gtest
        basic_head
        protobuf::libprotobuf
        grpc
        grpc++
        grpc++_reflection )

target_link_libraries(${project_name}
        gtest
        basic_head
        protobuf::libprotobuf
        grpc
        grpc++
        grpc++_reflection )

if(APPLE)
    # macOS 相关设置
elseif(WIN32)
    # Windows 相关设置
    target_link_libraries(${project_test_name}  ${project_name} ws2_32)
endif()
