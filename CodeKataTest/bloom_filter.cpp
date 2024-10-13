#include "pch.h"
#include "bloom_filter.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int BloomFilter::calculateHash(const string& str, int seed) {
    hash<string> hash_func;
    return (hash_func(str) ^ seed) % numberOfBit;
}

BloomFilter::BloomFilter(int no_of_bits, int no_of_hash) : numberOfBit(no_of_bits), numberOfHash(no_of_hash) {
    bits_array.resize(no_of_bits, false);
}

BloomFilter::~BloomFilter() {
    bits_array.clear();
}

void BloomFilter::addWord(string word) {
    for (int i = 0; i < numberOfHash; i++) {
        int idx = calculateHash(word, i);
        bits_array[idx] = true;
    }
}

bool BloomFilter::isWordContains(string word) {
    for (int i = 0; i < numberOfHash; i++) {
        int idx = calculateHash(word, i);
        if (!bits_array[idx]) return false;
    }

    return true;
}

BloomFilter  BloomFilter::createBloomFilter(vector<string> words, int no_of_bit, int no_of_hash) {
    BloomFilter filter = BloomFilter(no_of_bit, no_of_hash);

    for (auto w : words) {
        filter.addWord(w);
    }

    return filter;
}