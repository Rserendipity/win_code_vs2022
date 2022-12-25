class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int hash[26] = { 0 };
        for (char ch : s1) {
            hash[ch - 'a']++;
        }
        for (char ch : s2) {
            hash[ch - 'a']--;
        }
        for (int n : hash) {
            if (n != 0) {
                return false;
            }
        }
        return true;
    }
};