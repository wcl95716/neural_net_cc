#!/bin/bash

# 安装包
install_package() {
    local package_name=$1
    local package_version=$2
    
    # 检查包是否存在
    if [ ! -d "packages/$package_name" ]; then
        echo "Package $package_name not found"
        return 1
    fi
    
    # 构建包
    cd "packages/$package_name"
    mkdir -p build && cd build
    cmake .. && make
    cd ../../..
    
    echo "Installed $package_name@$package_version"
}

# 安装所有依赖
install_dependencies() {
    # 读取 packages.json
    local dependencies=$(cat packages.json | grep -o '"dependencies": {[^}]*}' | grep -o '"[^"]*": "[^"]*"')
    
    # 安装每个依赖
    while IFS= read -r dep; do
        if [ ! -z "$dep" ]; then
            local package_name=$(echo $dep | grep -o '"[^"]*":' | tr -d '":')
            local version=$(echo $dep | grep -o '"[^"]*"$' | tr -d '"')
            install_package $package_name $version
        fi
    done <<< "$dependencies"
}

# 主函数
case "$1" in
    "install")
        if [ -z "$2" ]; then
            install_dependencies
        else
            install_package $2 $3
        fi
        ;;
    *)
        echo "Usage: $0 install [package_name] [version]"
        ;;
esac 