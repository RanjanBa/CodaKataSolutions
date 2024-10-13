#include "pch.h"
#include "anagrams.h"

Anagrams::Anagrams(vector<string>& _words)
{
    words = _words;
    st.clear();

    for (auto w : words)
    {
        sort(w.begin(), w.end());
        st.insert(w);
    }
}

bool Anagrams::isEqualAnagramPresent(string word, string& res) {
    sort(word.begin(), word.end());
    if (st.find(word) != st.end()) {
        res = word;
        return true;
    }
    return false;
}