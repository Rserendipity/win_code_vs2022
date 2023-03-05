class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, dp = 0;
        for (char c : s) {
            if (c == 'a') {
                dp = min(dp + 1, countB);
            } else {
                countB++;
            }
        }
        return dp;
    }
};