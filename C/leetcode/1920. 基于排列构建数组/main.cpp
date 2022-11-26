#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> ans;
        ans.resize(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};
int main()
{

    return 0;
}
