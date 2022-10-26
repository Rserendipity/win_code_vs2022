#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sz = nums.size();
        for (int i = 1; i < sz; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};
int main()
{
    Solution s;
    return 0;
}
