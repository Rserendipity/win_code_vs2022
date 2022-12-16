#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (long long n : nums) {
            sum += n;
        }
        long long sub = abs(sum - goal);
        return (sub + limit - 1)/limit;
    }
};
int main()
{

    return 0;
}
