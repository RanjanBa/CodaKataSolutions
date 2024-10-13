#pragma once

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Anagrams
{
private:
    unordered_map<string, vector<string>> mp;
    void addWordToAnagram(string word);
public:
    Anagrams(vector<string>& _words);

    bool isEqualAnagramPresent(string word, string& res);
};
