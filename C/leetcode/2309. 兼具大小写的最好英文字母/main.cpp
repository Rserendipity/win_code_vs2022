class Solution {
public:
    string greatestLetter(string s) {
        int lower[26] = {0};
        int upper[26] = {0};
        for (char ch : s) {
            if (isupper(ch)) {
                upper[ch - 'A'] = 1;
            } else {
                lower[ch - 'a'] = 1;
            }
        }
        string ans;
        for (int i = 25; i >= 0; i--) {
            if (upper[i] && lower[i]) {
                ans += i + 'A';
                return ans;
            }
        }
        return "";
    }
};