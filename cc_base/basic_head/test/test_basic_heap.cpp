#include <iostream>
#include "basic_head.h"
#include "gtest/gtest.h"

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

TEST(TestCase, test4) {
	BasicHead basic_head;
	basic_head.addNum(2);
	EXPECT_EQ(2, basic_head.getTop());
	basic_head.addNum(3);
	EXPECT_EQ(2, basic_head.getTop());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	std::cout << "3463456456456 " << std::endl;
	std::cout << "3463456456456 " << std::endl;
	std::cout << "3463456456456 " << std::endl;
	std::cout << "3463456456456 " << std::endl;
	std::cout << "3463456456456 " << std::endl;
	//return RUN_ALL_TESTS();
}
