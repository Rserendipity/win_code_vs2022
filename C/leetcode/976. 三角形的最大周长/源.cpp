#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 1;
        int a = nums[nums.size() - index];
        int b = nums[nums.size() - ++index];
        int c = nums[nums.size() - ++index];

        while (index < nums.size() && b + c <= a) {
            a = b;
            b = c;
            c = nums[nums.size() - ++index];
        }

        if (b + c <= a) {
            return 0;
        }
        else {
            return a + b + c;
        }
    }
};
int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    Solution().largestPerimeter(v);
    return 0;
}
