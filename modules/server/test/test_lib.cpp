#include <iostream>
#include "../lib.h"
#include "basic_head/lib.h"


void SetupUserRoutes() {
    printf("asdasdasd111111111111");
    svr.Get("/user/get", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Get user information", "text/plain");
    });
    // ... 其他User模块的接
}

int main(int argc, char **argv) {
    BasicHead basic_head;
    basic_head.addNum(2);
    std::cout << basic_head.getTop() << std::endl;
    SetupUserRoutes();
    svr.listen("0.0.0.0", 8080);
	//return RUN_ALL_TESTS();
}
