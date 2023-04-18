class Solution {
public:
    string sortString(string s) {
        int hash[26] = {0};
        int n = s.size();
        string ans;
        for (char ch : s) {
            hash[ch-'a']++;
        }
        while (n) {
            for (int i = 0; i < 26 && n; i++) {
                if (hash[i]) {
                    ans.push_back('a' + i);
                    n--;
                    hash[i]--;
                }
            }
            for (int i = 25; i >= 0 && n; i--) {
                if (hash[i]) {
                    ans.push_back('a' + i);
                    n--;
                    hash[i]--;
                }
            }
        }
        return ans;
    }
};