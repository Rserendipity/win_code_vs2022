#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        ans.resize(2 * (long long)n);
        int head = 0;
        int mid = n;
        for (int i = 0; i < 2 * n; i++) {
            if (i % 2 == 0) {
                ans[i] = nums[head++];
            }
            else {
                ans[i] = nums[mid++];
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}
