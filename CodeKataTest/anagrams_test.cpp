#include <fstream>

#include "gtest/gtest.h"
#include "anagrams.h"

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

TEST(AngramsTest, AllTestCases) {
	vector<string> words = getLinesFromFile("words.txt");
	Anagrams anagrams(words);

	{
		string word = "";
		string sorted_word;
		bool s = anagrams.isEqualAnagramPresent(word, sorted_word);
		EXPECT_TRUE(s);
		string w = "";
		EXPECT_EQ(sorted_word, w);
	}

	{
		string word = "test";
		string sorted_word;
		bool s = anagrams.isEqualAnagramPresent(word, sorted_word);
		EXPECT_TRUE(s);
		string w = "estt";
		EXPECT_EQ(sorted_word, w);
	}
}


int main(int argc, char* argv[]) {
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}