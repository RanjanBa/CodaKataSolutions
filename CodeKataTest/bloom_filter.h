#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

class BloomFilter
{
private:
    vector<bool> bits_array;
    const int numberOfBit;
    const int numberOfHash;
    int calculateHash(const string& str, int seed);
public:
    BloomFilter(int no_of_bits, int no_of_hash);

    ~BloomFilter();

    void addWord(string word);

    bool isWordContains(string word);

    static BloomFilter createBloomFilter(vector<string> words, int no_of_bit, int no_of_hash);
};
