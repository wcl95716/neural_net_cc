#include <iostream>
#include "base/basic_head/lib.h"
#include "base/server/lib.h"

using namespace  std;


void SetupUserRoutes() {
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
