class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (auto& s : words) {
            if (pref.size() > s.size()) {
                continue;
            }
            int flag = 1;
            for (int i = 0; i < pref.size(); i++) {
                if (pref[i] != s[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
        return cnt;
    }
};