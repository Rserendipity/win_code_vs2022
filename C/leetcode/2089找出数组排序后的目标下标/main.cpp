#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int head = 0;
        int tail = nums.size() - 1;
        int mid = (head + tail) / 2;
        int flag = 0;
        while (head <= tail) {
            if (nums[mid] < target) {
                head = mid + 1;
            }
            else if (nums[mid] > target) {
                tail = mid - 1;
            }
            else {
                flag = 1;
                break;
            }
            mid = (head + tail) / 2;
        }
        vector<int> ret;
        if (flag == 0) {
            return ret;
        }
        else {
            head = mid;
            tail = mid;
            while (head >= 0 && nums[head] == target) {
                head--;
            }
            while (tail <= nums.size() - 1 && nums[tail] == target) {
                tail++;
            }
            for (int i = head + 1; i < tail; i++) {
                ret.push_back(i);
            }
            return ret;
        }
    }
};
int main() 
{
    // Solution s;
    // vector<int> nums = { 1,2,5,2,3 };
    // s.targetIndices(nums, 5);
    string s = "123";
    cout << s.size() << endl;
    return 0;
}
