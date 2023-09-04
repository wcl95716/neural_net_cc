//
// Created by Panda on 2021/6/21.
//

#include "lib.h"

using std::swap;

void test(){
    BasicHead basic_head;
    basic_head.addNum(2);
    std::cout<<basic_head.getTop()<<std::endl;
    basic_head.addNum(1);
    std::cout<<basic_head.getTop()<<std::endl;
}

void SetupUserRoutes() {
    svr.Get("/user/get", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Get user information", "text/plain");
    });
    // ... 其他User模块的接
}