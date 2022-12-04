#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> hash;
        for (char ch : s) {
            hash[ch]++;
        }
        int even = 0;
        int sum = 0;
        for (auto& kv : hash) {
            // cout << kv.first << ":" << kv.second << endl;
            if (kv.second >= 2) {
                if (kv.second % 2 == 1) {
                    if (even == 0)
                        even++;
                    kv.second--;
                }
                sum += kv.second;
            }
            else if (kv.second == 1 && even == 0) {
                even++;
            }
        }
        return sum + even;
    }
};
int main()
{
    Solution().longestPalindrome("aaaAaaaa");
    return 0;
}
