#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hash1;
        map<char, char> hash2;
        for (int i = 0; i < s.size(); i++) {
            hash1[s[i]] = t[i];
            hash2[t[i]] = s[i];
        }

        if (hash1.size() != hash2.size()) {
            return false;
        }
        auto it1 = hash1.begin();
        auto it2 = hash2.begin();
        while (it1 != hash1.end()) {
            if (it1->first != it2->second || it1->second != it2->first) {
                return false;
            }
            ++it1;
            ++it2;
        }
        return true;
    }
};
int main()
{
    Solution().isIsomorphic("qwertyuiop[]asdfghjkl;'\\zxcvbnm,./" ,"',.pyfgcrl/=aoeuidhtns-\\;qjkxbmwvz");

    return 0;
}
