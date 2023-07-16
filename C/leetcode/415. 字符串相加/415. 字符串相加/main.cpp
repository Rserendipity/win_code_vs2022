class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans;
        int i = 0, j = 0, carry = 0;
        while (i < num1.size() || j < num2.size() || carry) {
            int sum = carry;
            if (i < num1.size()) {
                sum += num1[i++] - '0';
            }
            if (j < num2.size()) {
                sum += num2[j++] - '0';
            }

            carry = sum / 10;
            sum %= 10;
            ans += (char)sum + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};