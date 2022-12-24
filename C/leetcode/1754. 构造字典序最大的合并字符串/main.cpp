#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int cmp(string::iterator it1, string::iterator it2) {
        while (*it1 == *it2) {
            ++it1;
            ++it2;
        }
        return *it1 - *it2;
    }
public:
    string largestMerge(string word1, string word2) {
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        string ans;
        int i = 0;
        while (it1 != word1.end() && it2 != word2.end()) {
            if (*it1 > *it2) {
                ans += *it1;
                ++it1;
            }
            else if (*it1 < *it2) {
                ans += *it2;
                ++it2;
            }
            else {
                if (string(it1, word1.end()).compare(string(it2, word2.end())) < 0) {
                    ans += *it2;
                    ++it2;
                }
                else {
                    ans += *it1;
                    ++it1;
                }
            }
        }

        if (it1 != word1.end()) {
            ans += string(it1, word1.end());
        }
        if (it2 != word2.end()) {
            ans += string(it2, word2.end());
        }
        return ans;
    }
};
int main()
{
    Solution().largestMerge("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb", "bbbbbbbbbbbbbbbbbbbb");
    return 0;
}
