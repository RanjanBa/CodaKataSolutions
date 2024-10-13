#pragma once

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Anagrams
{
private:
    vector<string> words;
    unordered_set<string> st;
public:
    Anagrams(vector<string>& _words);

    bool isEqualAnagramPresent(string word, string& res);
};
