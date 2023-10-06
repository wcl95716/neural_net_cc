#include <iostream>
#include "gtest/gtest.h"
#include "modules/basic_head/lib.h"
#include "modules/server/lib.h"
#include "zmy_template/lib.h"

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



int main(int argc, char **argv) {
    StringTest();

//    return RUN_ALL_TESTS();
}
                        