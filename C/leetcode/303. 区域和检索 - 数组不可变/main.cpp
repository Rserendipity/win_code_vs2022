#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums)
        : v(nums)
    {}

    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; i++) {
            sum += v[i];
        }
        return sum;
    }
private:
    vector<int> v;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
int main()
{

    return 0;
}
