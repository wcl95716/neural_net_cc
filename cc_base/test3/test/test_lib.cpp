#include <iostream>
#include "basic_head/basic_head.h"
#include "cpp-httplib/httplib.h"
#include "../lib.h"
void SetupUserRoutes() {
    printf("asdasdasd111111111111");
    svr.Get("/user/get", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Get user information", "text/plain");
    });
    // ... 其他User模块的接
}

int main(int argc, char **argv) {
    SetupUserRoutes();
    svr.listen("0.0.0.0", 8080);
	//return RUN_ALL_TESTS();
}
