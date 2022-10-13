#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
//class Solution {
//public:
//    bool containsNearbyDuplicate(vector<int>& nums, int k) {
//        map<int, int> hash;
//        for (int i = 0; i < nums.size(); i++) {
//            auto temp = hash.find(nums[i]);
//            if (temp != hash.end()) {
//                if (abs(temp->second - i) <= k) {
//                    return true;
//                }
//                else {
//
//                }
//            }
//            else {
//                hash[nums[i]] = i;
//            }
//        }
//        return false;
//    }
//};
//class Solution {
//public:
//    int addDigits(int num) {
//        string s = to_string(num);
//        while (s.size() != 1) {
//            int sum = 0;
//            for (int i = 0; i < s.size(); i++) {
//                sum = sum * 10 + s[i] - '0';
//            }
//            s.clear();
//            s = to_string(sum);
//        }
//        return s[0] - '0';
//    }
//};
class Solution {
public:
    bool isUgly(int n) {
        int temp = 2;

        while (n != 1) {
            if (n % temp == 0) {
                n /= temp;
            }
            else {
                temp++;
            }
            if (temp > 5) {
                return false;
            }
        }
        return true;
    }
};
int main() 
{
    Solution s;
    cout << s.isUgly(6) << endl;
    return 0;
}
