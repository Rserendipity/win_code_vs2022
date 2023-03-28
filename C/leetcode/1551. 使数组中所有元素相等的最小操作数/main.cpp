class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans += abs( (2*i + 1) - n);
        }
        return ans;
    }
};