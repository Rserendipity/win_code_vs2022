#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumMoves(string s) {
        int sz = s.size();
        int i = 0;
        int ans = 0;
        while (i < sz) {
            if (s[i] == 'X') {
                i += 3;
                ans++;
            }
            else {
                i++;
            }
        }
        return ans;
    }
};
int main()
{
    Solution().minimumMoves("XXOX");
    return 0;
}
