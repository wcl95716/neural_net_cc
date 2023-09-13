# CMakeLists.txt

cmake_minimum_required(VERSION 3.19)
#库的名字
# 获取当前文件夹名
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(project_name  ${PROJECT_NAME})
set(project_test_name  ${PROJECT_NAME}_test)
set(project_test_service  ${PROJECT_NAME}_service)

# 设置项目名称
project(${project_name})

set(CMAKE_CXX_STANDARD 14)
# Set _WIN32_WINNT value to 0x600 to support Windows Vista and later
add_definitions(-D_WIN32_WINNT=0x600)

include(FetchContent)
set(ABSL_ENABLE_INSTALL ON)
# 获取gRPC库
FetchContent_Declare(
        grpc
        GIT_REPOSITORY https://github.com/grpc/grpc.git
        GIT_TAG        v1.58.0
        GIT_SUBMODULES_RECURSE TRUE
)

FetchContent_GetProperties(grpc)
if(NOT grpc_POPULATED)
    FetchContent_Populate(grpc)
    # 使用gRPC的CMake项目
    add_subdirectory(${grpc_SOURCE_DIR} ${grpc_BINARY_DIR})
endif()

# Define your proto files
set(PROTO_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/protos/)
set(PROTO_FILES ${PROTO_SRC_DIR}/proto_file.proto)
# 关键配置
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

foreach(PROTO_FILE ${PROTO_FILES})
    get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
    set(PROTO_SRC ${CMAKE_CURRENT_BINARY_DIR}/${PROTO_NAME}.pb.cc)
    set(PROTO_HDR ${CMAKE_CURRENT_BINARY_DIR}/${PROTO_NAME}.pb.h)
    set(GRPC_SRC ${CMAKE_CURRENT_BINARY_DIR}/${PROTO_NAME}.grpc.pb.cc)
    set(GRPC_HDR ${CMAKE_CURRENT_BINARY_DIR}/${PROTO_NAME}.grpc.pb.h)

    add_custom_command(
            OUTPUT "${PROTO_SRC}" "${PROTO_HDR}" "${GRPC_SRC}" "${GRPC_HDR}"
            COMMAND protobuf::protoc
            ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
            --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
            -I "${PROTO_SRC_DIR}"
            --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
            "${PROTO_FILE}"
            DEPENDS "${PROTO_FILE}")
endforeach()


#设置库
add_library(${project_name} STATIC lib.h lib.cpp  ${PROTO_SRC} ${PROTO_HDR} ${GRPC_SRC} ${GRPC_HDR})

#测试方法
#客户端
add_executable(${project_test_name} test/test_lib.cpp  ${PROTO_SRC} ${PROTO_HDR} ${GRPC_SRC} ${GRPC_HDR})
#服务端
add_executable(${project_test_service} service/test_lib.cpp  ${PROTO_SRC} ${PROTO_HDR} ${GRPC_SRC} ${GRPC_HDR})

# target_sources(${project_test_name} PRIVATE ${PROTO_SRC} ${GRPC_SRC})

# 将工程目录添加到target_include_directories  这样可以方便引用其它文件的库
get_filename_component(Root_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)

# 添加上上层目录到包含目录

target_include_directories(${project_test_name} PRIVATE ${Root_DIR})
target_include_directories(${project_name} PRIVATE ${Root_DIR})

target_include_directories(${project_name} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${project_test_name}  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(${project_test_service}  PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
#测试方法链接库

target_link_libraries(${project_test_service} ${project_name}
        gtest
        protobuf::libprotobuf
        grpc
        grpc++
        grpc++_reflection )

target_link_libraries(${project_test_name} ${project_name}
        gtest
        protobuf::libprotobuf
        grpc
        grpc++
        grpc++_reflection )

target_link_libraries(${project_name}
        protobuf::libprotobuf
        grpc
        grpc++
        grpc++_reflection )

#if(APPLE)
#    # macOS 相关设置
#elseif(WIN32)
#    # Windows 相关设置
#    target_link_libraries(${project_test_name}  ${project_name} ws2_32)
#endif()
