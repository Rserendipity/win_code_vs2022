#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (begin + end) / 2;
        while (begin <= end) {
            if (nums[begin] > nums[end]) {
                if (nums[begin] <= nums[mid]) {
                    begin = mid + 1;
                }
                else {
                    end = mid;
                }
            }
            else if (nums[begin] < nums[end]) {
                end = mid;
            }
            else {
                return nums[begin];
            }
            mid = (begin + end) / 2;
        }
        return nums[begin];
    }
};
int main()
{
    vector<int> ans = { 5,6,7,0,1,2,4 };
    Solution().findMin(ans);
    return 0;
}
