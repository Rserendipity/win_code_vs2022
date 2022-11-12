#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int tmp[2002] = { 0 };
        int ans = 0;
        for (auto& n : arr) {
            tmp[n]++;
        }
        for (int i = 1; i <= 2001; i++) {
            if (k == 0) {
                ans = i - 1;
                break;
            }
            if (tmp[i] == 0)
                k--;
        }
        return ans;
    }
};
int main()
{

    return 0;
}
