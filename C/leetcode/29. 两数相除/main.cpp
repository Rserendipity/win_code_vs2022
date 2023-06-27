class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (dividend / divisor > INT_MAX)
            return INT_MAX;
        else if (dividend / divisor < INT_MIN)
            return INT_MIN;
        else
            return dividend / divisor;
    }
};