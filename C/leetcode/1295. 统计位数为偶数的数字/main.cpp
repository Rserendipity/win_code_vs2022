class Solution {
    int isPrime(int n) {
        if (n < 10) {
            return 0;
        } else if (n < 100) {
            return 1;
        } else if (n < 1000) {
            return 0;
        } else if (n < 10000) {
            return 1;
        } else if (n < 100000) {
            return 0;
        } else if (n < 1000000) {
            return 1;
        } else if (n < 10000000) {
            return 0;
        }
        return 1;
    }
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int n : nums) {
            if (isPrime(n))
                ans++;
        }
        return ans;
    }
};