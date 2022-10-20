#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int max = sum;
        for (int i = k; i < size; i++) {
            sum = sum - nums[i - k] + nums[i];
            max = sum > max ? sum : max;
        }
        return (double)max / k;
    }
};
int main()
{

    return 0;
}
