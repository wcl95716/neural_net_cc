#include <iostream>
#include "gtest/gtest.h"
#include "core/basic_custom_heap/lib.h"
#include "core/server/lib.h"

TEST(TestCase, test_BasicHead) {
    BasicHead basic_custom_heap;
    basic_custom_heap.addNum(2);
    EXPECT_EQ(2, basic_custom_heap.getTop() );
    basic_custom_heap.addNum(3);
    EXPECT_EQ(2, basic_custom_heap.getTop() );
    basic_custom_heap.addNum(1);
    EXPECT_EQ(1, basic_custom_heap.getTop() );
}

TEST(TestCase, test_BasicHead_pop) {
    BasicHead basic_custom_heap;
    basic_custom_heap.addNum(2);
    basic_custom_heap.addNum(3);
    basic_custom_heap.addNum(1);
    EXPECT_EQ(1, basic_custom_heap.getTop() );
    basic_custom_heap.delTop();
    EXPECT_EQ(2, basic_custom_heap.getTop() );
    basic_custom_heap.delTop();
    EXPECT_EQ(3, basic_custom_heap.getTop() );
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
