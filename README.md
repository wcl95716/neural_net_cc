# neural_net_cc


# 需要同时clone 子模块 

``` shell
git submodule update --init --recursive
```

# grpc windows 错误修复

你的错误消息表明在re2库的pcre.h头文件中有一个未被识别的类型（int32_t）。这个库是grpc的第三方依赖。错误消息也建议包括<cstdint>，因为int32_t是在其中定义的。

要解决此问题，请按照以下步骤操作：

包括缺失的头文件：
打开文件：

``` bash 
neural_net_cc/cmake-build-debug/_deps/grpc-src/third_party/re2/util/pcre.h
```
在文件顶部添加这个include语句：
``` cpp
#include <cstdint>
```