#include <fstream>

#include "gtest/gtest.h"
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

TEST(BloomFilterTest, AllTestCases) {
	vector<string> lines = getLinesFromFile("words_sample.txt");
	BloomFilter bloom_filter = BloomFilter::createBloomFilter(lines, 1e5, 3);

	string word = "Blimps1dwd";
	bool is_found = bloom_filter.isWordContains(word);

	EXPECT_FALSE(is_found);
	EXPECT_TRUE(is_found);
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}