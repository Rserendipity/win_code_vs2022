class Solution {
public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string ans;
        for (int i = 0; i < k; i++) {
            ss >> s;
            ans += s;
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};