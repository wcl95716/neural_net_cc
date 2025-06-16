#pragma once

#include "../base_template.h"

BASE_TEMPLATE_NAMESPACE_BEGIN
    template<typename T>
    void swap(T& a, T& b) {
        T temp = a;
        a = b;
        b = temp;
    }
BASE_TEMPLATE_NAMESPACE_END 