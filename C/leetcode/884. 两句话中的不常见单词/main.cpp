#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#include <cstring>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map<string, int> hash;
        s1 += " ";
        s1 += s2;
        s1 += " ";
        auto begin = s1.begin();
        auto move = s1.begin();
        while (move != s1.end()) {
            if (*move == ' ') {
                hash[string(begin, move)]++;
                begin = ++move;
            }
            else {
                ++move;
            }
        }
        for (auto& kv : hash) {
            if (kv.second == 1) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }
};
int main()
{
    Solution().uncommonFromSentences("this apple is sweet", "this apple is sour");
    return 0;
}
