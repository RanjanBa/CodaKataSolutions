#pragma once

#include "pch.h"
#include "sort_it_out.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

SortingBalls::SortingBalls(int number_of_balls) : total_number_of_balls(number_of_balls) {
    is_available = vector<bool>(number_of_balls, false);
}

void SortingBalls::addBall(int number) {
    if (number < 0 || number >= total_number_of_balls) {
        cout << "Please provide valid ball number between 0 and " << (total_number_of_balls - 1) << "." << endl;
        return;
    }

    is_available[number] = true;
}

vector<int> SortingBalls::getBalls() {
    vector<int> balls;

    for (int i = 0; i < total_number_of_balls; i++) {
        if (is_available[i]) {
            balls.push_back(i);
        }
    }

    return balls;
}


string SortingCharacters::sortCharacter(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    vector<int> freq(26, 0);
    for (char ch : str) {
        if ('a' <= ch && ch <= 'z') {
            int idx = ch - 'a';
            freq[idx]++;
        }
    }

    string res;

    for (int i = 0; i < 26; i++) {
        while (freq[i]--) {
            char ch = 'a' + i;
            res += ch;
        }
    }

    return res;
}