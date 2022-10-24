#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        int LeftMax = nums[0], curMax = nums[0];
        int pos = 0;
        for (int i = 1; i < n; i++) {
            curMax = max(curMax, nums[i]);
            if (nums[i] < LeftMax) {
                pos = i;
                LeftMax = curMax;
            }
        }
        return pos + 1;
    }
};
int main()
{

    return 0;
}
