#include "pch.h"
#include "anagrams.h"

Anagrams::Anagrams(vector<string>& _words)
{
    mp.clear();

    for (auto w : _words)
    {
        addWordToAnagram(w);
    }
}

void Anagrams::addWordToAnagram(string word) {
    string w = word;
    sort(w.begin(), w.end());
    if (mp.find(w) != mp.end()) {
        mp[w].push_back(word);
    }
    else {
        mp[w] = { word };
    }
}

bool Anagrams::isEqualAnagramPresent(string word, string& sorted_word) {
    sort(word.begin(), word.end());
    if (mp.find(word) != mp.end()) {
        sorted_word = word;
        return true;
    }
    return false;
}