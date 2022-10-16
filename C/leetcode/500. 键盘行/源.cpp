#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        const string enum_keyBoard[3] = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
        vector<string> ans;
        int flag = 0;
        for (auto& s : words) {
            for (int i = 0; i < 3; i++) {
                if (enum_keyBoard[i].find(tolower(s[0])) != enum_keyBoard[i].npos) {
                    flag = i;
                    break;
                }
            }
            for (auto& ch : s) {
                if (enum_keyBoard[flag].find(tolower(ch)) == enum_keyBoard[flag].npos) {
                    flag = 4;
                    break;
                }
            }
            if (flag != 4) {
                ans.push_back(s);
            }
        }
        return ans;
    }
};
int main() 
{

    return 0;
}
