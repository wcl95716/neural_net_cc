# 添加可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 链接所有包
target_link_libraries(${PROJECT_NAME} PRIVATE ${ALL_PACKAGES}) 