#include <iostream>
#include "cc_base/test1/lib.h"
#include "cc_base/basic_head/lib.h"
#include "cc_base/server/lib.h"

using namespace  std;


void SetupUserRoutes() {
    printf("asdasdasd111111111111");
    svr.Get("/user/get", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Get user information", "text/plain");
    });
    // ... 其他User模块的接
}

int main()
{
//    BasicHead basic_head;
//    basic_head.addNum(2);
//    cout<<basic_head.getTop()<<endl;
//    basic_head.addNum(3);

    SetupUserRoutes();
    svr.listen("0.0.0.0", 8080);

}
