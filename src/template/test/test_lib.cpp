#include <iostream>
#include "gtest/gtest.h"
#include "modules/basic_head/lib.h"
#include "modules/server/lib.h"

TEST(TestCase, test_BasicHead) {
    BasicHead basic_head;
    basic_head.addNum(2);
    EXPECT_EQ(2, basic_head.getTop() );
    basic_head.addNum(3);
    EXPECT_EQ(2, basic_head.getTop() );
    basic_head.addNum(1);
    EXPECT_EQ(1, basic_head.getTop() );
}

TEST(TestCase, test_BasicHead_pop) {
    BasicHead basic_head;
    basic_head.addNum(2);
    basic_head.addNum(3);
    basic_head.addNum(1);
    EXPECT_EQ(1, basic_head.getTop() );
    basic_head.delTop();
    EXPECT_EQ(2, basic_head.getTop() );
    basic_head.delTop();
    EXPECT_EQ(3, basic_head.getTop() );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
