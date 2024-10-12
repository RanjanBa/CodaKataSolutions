#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Anagrams
{
private:
    vector<string> words;
    unordered_set<string> st;

public:
    Anagrams(vector<string> &_words)
    {
        words = _words;
        st.clear();

        for (auto w : words)
        {
            sort(w.begin(), w.end());
            st.insert(w);
        }
    }

    bool isEqualAnagramPresent(string word, string &res) {
        sort(word.begin(), word.end());
        if(st.find(word) != st.end()) {
            res = word;
            return true;
        }
        return false;
    }
};

class AnagramsUtility
{
private:
    static void findAnagrams(string &word, string &cur_anagram, unordered_set<string> &res)
    {
        if (word.size() == 0)
        {
            if (cur_anagram.size())
            {
                res.insert(cur_anagram);
            }
            return;
        }

        for (int i = 0; i < word.size(); i++)
        {
            string new_word;
            if (i != 0)
            {
                new_word = word.substr(0, i);
            }

            if (i < word.size() - 1)
            {
                new_word += word.substr(i + 1);
            }

            cur_anagram.push_back(word[i]);

            findAnagrams(new_word, cur_anagram, res);
            cur_anagram.pop_back();
        }
    }

public:
    static vector<string> getAllAnagrams(string word)
    {
        unordered_set<string> anagrams;
        string cur_anagram;
        findAnagrams(word, cur_anagram, anagrams);

        vector<string> res(anagrams.begin(), anagrams.end());
        return res;
    }
};

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "You haven't provided input filename. Please provide filename." << endl;
        return 1;
    }

    string filename = argv[1];

    ifstream inputFile(filename);

    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<string> words;
    string line;

    while (getline(inputFile, line))
    {
        words.push_back(line);
    }

    Anagrams anagrams(words);
    
    unordered_map<string, set<string>> mp;

    for(auto str : words) {
        string s;
        if(anagrams.isEqualAnagramPresent(str, s)) {
            mp[s].insert(str);
        }
    }

    vector<vector<string>> res;

    for(auto v : mp) {
        if(v.second.size() > 1) res.push_back(vector<string>(v.second.begin(), v.second.end()));
    }

    int total_words = 0;
    for(auto v : res) {
        for(auto s : v) {
            cout << s << " ";
        }
        cout << endl;
        total_words += v.size();
    }

    cout << "Total anagrams group : " << res.size() << endl;
    cout << "Total anagrams words : " << total_words << endl;

    // for (string word : words)
    // {
    //     vector<string> res = AnagramsUtility::getAllAnagrams(word);
    //     for (auto str : res)
    //     {
    //         cout << str << " ";
    //     }
    //     cout << endl;
    // }

    inputFile.close();

    return 0;
}