#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < salary.size(); i++) {
            if (salary[i] < salary[min]) {
                min = i;
            }
            else if (salary[i] > salary[max]) {
                max = i;
            }
        }
        double ans = 0;
        for (int i = 0; i < salary.size(); i++) {
            if (i == min || i == max) {
                continue;
            }
            ans += salary[i];
        }
        return ans / (double)(salary.size() - 2);
    }
};
int main() 
{
    Solution s;
    // map<vector<int, int>, bool> hash;

    // hash[{1, 0}] = true;

    vector<int> nums = { 1000, 2000, 3000 };
    cout << s.average(nums) << endl;
    return 0;
}
