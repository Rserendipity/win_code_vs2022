#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            if (hash.insert(make_pair(nums[i], i)).second)
            {
            }
            else
            {
                if (abs(hash[nums[i]] - i) <= k)
                    return true;
                else
                    hash[nums[i]] = i;
            }
        }
        return false;
    }
};