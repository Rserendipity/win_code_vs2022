#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
//class Solution {
//public:
//    vector<string> uncommonFromSentences(string s1, string s2) {
//        vector<string> ans;
//        map<string, int> hash;
//        int begin = 0;
//        int count = 0;
//        for (int i = 0; i < s1.size() + 1; i++) {
//            if (s1[i] == ' ' || s1[i] == '\0') {
//                hash[s1.substr(begin, count)]++;
//                begin = i + 1;
//                count = 0;
//            }
//            else {
//                count++;
//            }
//        }
//        begin = 0;
//        count = 0;
//        for (int i = 0; i < s2.size() + 1; i++) {
//            if (s2[i] == ' ' || s2[i] == '\0') {
//                hash[s2.substr(begin, count)]++;
//                begin = i + 1;
//                count = 0;
//            }
//            else {
//                count++;
//            }
//        }
//
//        for (auto& kv : hash) {
//            if (kv.second == 1) {
//                ans.push_back(kv.first);
//            }
//           /* cout << kv.first << endl;
//            cout << kv.second << endl;*/
//        }
//        return ans;
//    }
//};


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 == 1 && nums[right] % 2 == 0) {
                swap(nums[left], nums[right]);
            }
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }
            while (left < right && nums[right] % 2 == 1) {
                right--;
            }
        }
        return nums;
    }
}; 
int main() 
{
    Solution s;
    vector<int> a = { 3,1,2,4 };
    vector<int> ans = s.sortArrayByParity(a);
    for (auto& s : ans) {
        cout << s << endl;
    }
    return 0;
}
