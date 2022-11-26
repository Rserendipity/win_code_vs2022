#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> ans;
        int sz = nums.size();
        ans.resize(sz * 2);
        for (int i = 0; i < sz; i++)
        {
            ans[i] = ans[i + sz] = nums[i];
        }
        return ans;
    }
};
int main()
{

    return 0;
}
