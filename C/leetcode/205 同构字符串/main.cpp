#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> hash;
        for (int i = 0; i < s.size(); i++) {
            auto fd = s.find(s[i]);
            if (fd == s.npos) {
                hash[s[i]] = t[i];
            }
            else {
                if (hash[s[fd]] == t[i]) {

                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() 
{
    Solution s;
    cout << s.isIsomorphic("add", "egg");
    map<int, bool> hash;
    hash[0] = true;
    if (hash[0] == true) {
        cout << 123534 << endl;
    }


    return 0;
}
