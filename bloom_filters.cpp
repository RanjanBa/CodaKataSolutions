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
    int calculateHash(const string &str, int seed) {
        hash<string> hash_func;
        return (hash_func(str) ^ seed) % numberOfBit;
    }
public:
    BloomFilter(int no_of_bits, int no_of_hash) : numberOfBit(no_of_bits), numberOfHash(no_of_hash) {
        bits_array.resize(no_of_bits, false);
    }

    ~BloomFilter() {
        bits_array.clear();
    }

    void addWord(string word) {
        for(int i = 0; i < numberOfHash; i++) {
            int idx = calculateHash(word, i);
            bits_array[idx] = true;
        }
    }

    bool isWordContains(string word) {
        for(int i = 0; i < numberOfHash; i++) {
            int idx = calculateHash(word, i);
            if(!bits_array[idx]) return false;
        }

        return true;
    }
};

BloomFilter createBloomFilter(vector<string> words, int no_of_bit, int no_of_hash) {
    BloomFilter filter = BloomFilter(no_of_bit, no_of_hash);

    for(auto w : words) {
        filter.addWord(w);
    }

    return filter;
}

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

    BloomFilter filter = createBloomFilter(words, 1e5, 1000);

    string word = "Testerddwad";

    bool isWordContain = filter.isWordContains(word);

    if(isWordContain) {
        cout << "Word : " << word << " is probably contains in filter.\n" << endl;
    } else {
        cout << "Word : " << word << " doesn't contain in filter.\n" << endl;
    }

    return 0;
}