#pragma once

// 命名空间宏定义
#define BASE_TEMPLATE_NAMESPACE_BEGIN namespace base_template {
#define BASE_TEMPLATE_NAMESPACE_END }

// 定义统一的命名空间
BASE_TEMPLATE_NAMESPACE_BEGIN
    // 导出所有功能
    #include "core/base.h"
BASE_TEMPLATE_NAMESPACE_END 