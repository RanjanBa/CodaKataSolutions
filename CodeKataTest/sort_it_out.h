#pragma once

#include <vector>
#include <string>

using namespace std;

class SortingBalls {
private:
    vector<bool> is_available;
    const int total_number_of_balls;
public:
    SortingBalls(int number_of_balls);

    void addBall(int number);

    vector<int> getBalls();
};

class SortingCharacters {
public:
    static string sortCharacter(string str);
};