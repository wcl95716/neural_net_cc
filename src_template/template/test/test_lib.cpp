#include <iostream>
#include "gtest/gtest.h"
#include "cc_base/basic_head/lib.h"
#include "cc_base/server/lib.h"

int add(int x, int y) {
    return x + y;
}

TEST(TestCase, test1) {
    ASSERT_EQ(12, add(4, 8));
}

TEST(TestCase, test2) {
    EXPECT_EQ(5, add(2, 3));
}

TEST(TestCase, test3) {
    EXPECT_EQ(3, add(1, 2));
}

void SetupUserRoutes() {
    svr.Get("/", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Get user information", "text/plain");
    });
    // ... 其他User模块的接
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    BasicHead basic_head;
    basic_head.addNum(2);
    std::cout << basic_head.getTop() << std::endl;
     SetupUserRoutes();
     svr.listen("0.0.0.0", 8080);
    return RUN_ALL_TESTS();
}
