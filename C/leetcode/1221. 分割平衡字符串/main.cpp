class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, R = 0, L = 0;
        for (char ch : s) {
            if (ch == 'R')
                R++;
            else 
                L++;
            if (R && L && R == L) {
                ans++;
                R = L = 0;
            }
        }
        return ans;
    }
};