class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int hash_s[26] = {0};
        for (char ch : s) {
            hash_s[ch - 'a']++;
        }
        int ans = 0;
        int flag = 1;
        while (true) {
            for (char ch : target) {
                hash_s[ch - 'a']--;
            }
            for (int i = 0; i < 26; i++) {
                if (hash_s[i] < 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
    }
};