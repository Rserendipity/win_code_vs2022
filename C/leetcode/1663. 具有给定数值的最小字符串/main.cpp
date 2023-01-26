class Solution {
    char word[27] = {0,'a','b','c','d','e','f','g',
                    'h','i','j','k','l','m','n',
                    'o','p','q','r','s','t',
                    'u','v','w','x','y','z'};
    void get(int n, int k, string& ans) {
        if (n <= 0 || k <= 0) {
            return;
        }
        int tmp = k - n + 1;
        if (tmp >= 26) {
            ans += word[26];
            get(n - 1, k - 26, ans);
        } else {
            ans += word[tmp];
            get(n - 1, k - tmp, ans);
        }
    }
public:
    string getSmallestString(int n, int k) {
        string ans;
        get(n, k, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};