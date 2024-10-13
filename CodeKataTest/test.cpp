#include <fstream>

#include "pch.h"
#include "karate_chop.h"
#include "anagrams.h"
#include "counting_code_lines.h"
#include "sort_it_out.h"
#include "bloom_filter.h"

vector<string> getLinesFromFile(string filename) {
	ifstream inputFile(filename);

	if (!inputFile.is_open())
	{
		cerr << "Error opening file: " << filename << endl;
		return {};
	}

	vector<string> lines;
	string line;

	while (getline(inputFile, line))
	{
		lines.push_back(line);
	}

	return lines;
}

TEST(KarateChopTest, AllTestCases) {
	KarateChop chop;
	vector<int> vec = { 1, 2, 3 };
	int pos = chop.findPos(1, vec);
	EXPECT_EQ(0, pos);
	pos = chop.findPos(4, vec);
	EXPECT_EQ(-1, pos);
	pos = chop.findPos(3, vec);
	EXPECT_EQ(2, pos);
}

TEST(AngramsTest, AllTestCases) {
	vector<string> words = {"test", "ranjan"};
	Anagrams anagrams(words);
	string word = "test";
	string res;
	bool s = anagrams.isEqualAnagramPresent(word, res);
	EXPECT_TRUE(s);
	string w = "estt";
	EXPECT_EQ(res, w);
}

TEST(CountingCodeLinesTest, AllTestCases) {
	int lines = calculateNumberOfCodeLines("code_lines.txt");

	EXPECT_EQ(13, lines);
}

TEST(SortItOutTest, AllTestCases) {
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

TEST(BloomFilterTest, AllTestCases) {
	vector<string> lines = getLinesFromFile("words.txt");
	BloomFilter bloom_filter = BloomFilter::createBloomFilter(lines, 1e5, 3);

	string word = "test";
	bool is_found = bloom_filter.isWordContains(word);

	EXPECT_FALSE(is_found);
	EXPECT_TRUE(is_found);
}