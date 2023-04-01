class Solution {
public:
    string maskPII(string s) {
        // 邮件
        auto ft = s.find('@');
        string ans;
        if (ft != s.npos) {
            string tmp = s.substr(0, ft);
            ans += tmp.front();
            ans += "*****";
            ans += tmp.back();
            ans += s.substr(ft);
            for (char& ch : ans) {
                if (isupper(ch)) {
                    ch = ch - 'A' + 'a';
                }
            }
        } else { // 电话号码 
            int i = 0, j = 0, sz = s.size();
            for (; i < sz; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    s[j++] = s[i];
                }
            }
            j--;
            for (i = j, j -= 4; i > j; i--) {
                ans += s[i];
            }
            
            // 有国号的
            if (j > 5) {
                j -= 5;
                ans += "-***-***-";
                ans += string(j, '*');
                ans += '+';
            } else { // 无国家号码的
                ans += "-***-***";
            }

            // cout << ans << endl;
            // cout << j << endl;
            
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};