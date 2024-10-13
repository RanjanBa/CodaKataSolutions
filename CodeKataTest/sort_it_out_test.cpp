#include "gtest/gtest.h"
#include "sort_it_out.h"

TEST(SortItOutTest, SortingBallsCases) {
	SortingBalls sorting_balls(60);

	vector<int> res = {};

	EXPECT_EQ(res, sorting_balls.getBalls());

	res = { 20 };
	sorting_balls.addBall(20);
	EXPECT_EQ(res, sorting_balls.getBalls());

	res = { 10, 20 };
	sorting_balls.addBall(10);
	EXPECT_EQ(res, sorting_balls.getBalls());

	res = { 10, 20, 40 };
	sorting_balls.addBall(40);
	EXPECT_EQ(res, sorting_balls.getBalls());

	res = { 10, 20, 30, 40 };
	sorting_balls.addBall(30);
	EXPECT_EQ(res, sorting_balls.getBalls());
}

TEST(SortItOutTest, SortingCharactersCase) {
	string str = "";
	string output = "";
	EXPECT_EQ(output, SortingCharacters::sortCharacter(str));

	str = "ddaade";
	output = "aaddde";
	EXPECT_EQ(output, SortingCharacters::sortCharacter(str));

	str = "1dwadd$";
	output = "adddw";
	EXPECT_EQ(output, SortingCharacters::sortCharacter(str));
}

int main(int argc, char* argv[]) {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}