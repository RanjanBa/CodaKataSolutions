#include "gtest/gtest.h"
#include "karate_chop.h"

TEST(KarateChopTest, AllTestCases) {
	KarateChop chop;
	vector<int> vec;
	int pos = chop.findPos(1, vec);
	EXPECT_EQ(-1, pos);

	vec = { 1, 2, 3 };
	pos = chop.findPos(1, vec);
	EXPECT_EQ(0, pos);
	pos = chop.findPos(4, vec);
	EXPECT_EQ(-1, pos);
	pos = chop.findPos(3, vec);
	EXPECT_EQ(2, pos);
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}