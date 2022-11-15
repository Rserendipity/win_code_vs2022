class Solution {
public:
    int mul(int n) {
        if (n < 10) {
            return n;
        } else {
            return n % 10 * mul(n / 10);
        }
    }
    int sum(int n) {
        if (n < 10) {
            return n;
        } else {
            return n % 10 + sum(n / 10);
        }
    }
    int subtractProductAndSum(int n) {
        return mul(n) - sum(n);
    }
};