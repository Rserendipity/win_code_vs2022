class Solution {
public:
    int minNumBooths(vector<string>& demand) {
        int hash[26] = {0};
        int hash_t[26] = {0};
        for (string& s : demand) {
            memset(hash_t, 0, sizeof(hash_t));
            for (char ch : s) {
                hash_t[ch-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                hash[i] = max(hash[i], hash_t[i]);
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += hash[i];
        }
        return ans;
    }
};