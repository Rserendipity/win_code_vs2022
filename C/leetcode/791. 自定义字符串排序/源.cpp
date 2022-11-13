#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        for (auto ch : order) {
            auto it = find(s.begin(), s.end(), ch);
            while (it != s.end() ) {
                ans += ch;
                *it = 0;
                it = find(s.begin(), s.end(), ch);
            }
        }
        return ans;
    }
};
int main()
{
    cout << Solution().customSortString("cbafg", "abcd");
    return 0;
}
