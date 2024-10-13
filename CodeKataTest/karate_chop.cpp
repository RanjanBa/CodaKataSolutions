#include "pch.h"
#include "karate_chop.h"

KarateChop::KarateChop()
{
}

KarateChop::~KarateChop()
{
}

int KarateChop::findPos(int ele, const vector<int>& vec)
{
    // return chop(ele, vec, 0, vec.size() - 1);
    return findPosIterative(ele, vec, 0, vec.size() - 1);
}

int KarateChop::findPosRecursive(int ele, const vector<int>& vec, int first, int last)
{
    if (first > last)
        return -1;

    int mid = first + (last - first) / 2;

    if (ele == vec[mid])
    {
        return mid;
    }

    if (ele < vec[mid])
    {
        return findPosRecursive(ele, vec, first, mid - 1);
    }

    return findPosRecursive(ele, vec, mid + 1, last);
}

int KarateChop::findPosIterative(int ele, const vector<int>& vec, int first, int last)
{
    while (first <= last)
    {
        int mid = first + (last - first) / 2;
        if (ele == vec[mid])
        {
            return mid;
        }
        else if (ele < vec[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    return -1;
}