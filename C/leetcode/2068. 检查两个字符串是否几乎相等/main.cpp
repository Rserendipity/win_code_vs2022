class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int hash1[26] = {0};
        int hash2[26] = {0};
        for (char& ch : word1) {
            hash1[ch - 'a']++;
        }
        for (char& ch : word2) {
            hash2[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            cout << hash1[i] - hash2[i] << endl;
            if (abs(hash1[i] - hash2[i]) > 3)
                return false;
        }
        return true;
    }
};