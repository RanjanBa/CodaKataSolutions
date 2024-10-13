#pragma once

#include <vector>

using namespace std;

class KarateChop
{
public:
	KarateChop();
	~KarateChop();

    int findPos(int ele, const vector<int>& vec);

private:
    int findPosRecursive(int ele, const vector<int>& vec, int first, int last);

    int findPosIterative(int ele, const vector<int>& vec, int first, int last);
};
