class Solution {
public:
    bool digitCount(string num) {
        int hash[10] = {0};
        for (char ch : num) {
            hash[ch - '0']++;
        }
        for (int i = 0; i < num.size(); i++) {
            if (hash[i] != num[i] - '0') {
                return false;
            }
        }
        return true;
    }
};