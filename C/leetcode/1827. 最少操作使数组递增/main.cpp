#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                int result = nums[i - 1] + 1;
                cnt += result - nums[i];
                nums[i] = result;
            }
        }
        return cnt;
    }
};
int main()
{

    return 0;
}
