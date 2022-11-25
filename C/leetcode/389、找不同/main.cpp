#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int tmp[26] = { 0 };
        for (auto& ch : s) {
            tmp[ch - 'a']--;
        }
        for (auto& ch : t) {
            tmp[ch - 'a']++;
        }
        for (auto& n : tmp) {
            if (n == 1) {
                return 'a' + n;
            }
        }
        return 0;
    }
};
int main()
{
    Solution().findTheDifference("abc", "abcd");
    return 0;
}
