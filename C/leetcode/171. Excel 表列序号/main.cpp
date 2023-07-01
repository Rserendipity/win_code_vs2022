class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        long long carry = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            sum += (s[i] - 'A' + 1) * carry;
            carry *= 26;
        }
        return sum;
    }
};