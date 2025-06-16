#include <iostream>
#include "gtest/gtest.h"
#include "base_template.h"

// 测试 test 函数
TEST(BaseTemplateTest, TestFunction) {
	// 这里可以添加测试代码
	// 由于 test() 只是打印，我们可以测试它不会崩溃
	EXPECT_NO_THROW(base_template::test());
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
