//
// Created by Panda on 2021/6/21.
//

#include "lib.h"

using std::swap;

void test(){
    BasicHead basic_custom_heap;
    basic_custom_heap.addNum(2);
    std::cout<<basic_custom_heap.getTop()<<std::endl;
    basic_custom_heap.addNum(1);
    std::cout<<basic_custom_heap.getTop()<<std::endl;
}
