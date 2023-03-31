class Solution {
public:
    int sumNums(int n) {
        int ans = n;
        n && (ans += sumNums(n - 1));
        return ans;
    }
};