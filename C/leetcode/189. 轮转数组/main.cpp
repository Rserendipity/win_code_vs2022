#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // ����һ��
        // ����ʵʵ��һ��һ�������ƣ���k�Σ���ʱ��
        // ʱ�临�Ӷ� O(k*N) �ռ� O(1)
        // int sz = nums.size();
        // if (sz == 1) {
        //     return;
        // }
        // k %= sz;
        // while (k--) {
        //     int save = nums[sz - 1];
        //     for (int i = sz - 1; i > 0; i--) {
        //         nums[i] = nums[i - 1];
        //     }
        //     nums[0] = save;
        // }

        // ��������
        // ʹ�ø������飬�������������飬Ȼ�󿽱���ȥ
        // ʱ�临�Ӷ� O(N)    �ռ临�Ӷ� O(N)
        int sz = nums.size();
        if (sz == 1) {
            return;
        }
        vector<int> temp;
        temp.resize(sz);
        k %= sz;
        int index = 0;
        // 4,5,6
        for (int i = sz - k; i < sz; i++) {
            temp[index++] = nums[i];
        }
        // 0,1,2
        for (int i = 0; i <= k; i++) {
            temp[index++] = nums[i];
        }
        for (int i = 0; i < sz; i++) {
            nums[i] = temp[i];
        }


        // ��������
        // ������������������
        // ʱ�临�Ӷ� O(N)   �ռ临�Ӷ� O(1)
        // int sz = nums.size();
        // if (sz == 1) {
        //     return;
        // }
        // k %= sz;
    }
};
int main()
{
    vector<int> nums = { 1,2,3,4,5,6,7 };
    Solution s;
    s.rotate(nums, 3);

    for (auto& n : nums) {
        cout << n << " "; 
    }
    return 0;
}
