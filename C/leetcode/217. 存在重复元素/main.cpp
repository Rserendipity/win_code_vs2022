#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> hash;
        for (auto &n : nums)
        {
            hash[n]++;
        }
        for (auto &kv : hash)
        {
            if (kv.second >= 2)
            {
                return true;
            }
        }
        return false;
    }
};