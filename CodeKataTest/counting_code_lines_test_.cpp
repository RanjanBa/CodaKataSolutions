#include "gtest/gtest.h"
#include "counting_code_lines.h"


TEST(CountingCodeLinesTest, AllTestCases) {
	int lines = calculateNumberOfCodeLines("code_lines.txt");

	EXPECT_EQ(13, lines);
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}