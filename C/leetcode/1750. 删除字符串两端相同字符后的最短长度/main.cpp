class Solution {
public:
    int minimumLength(string s) {
        int begin = 0;
        int sz = s.size();
        int end = sz - 1;
        while (begin < end && s[begin] == s[end]) {
            // cout << s[begin] << " " << s[end] << endl;
            while (begin < sz && s[begin] == s[begin + 1]) {
                begin++;
            }
            while (end > 0 && s[end] == s[end - 1]) {
                end--;
            }
            begin++;
            end--;
        }
        if (begin > end) {
            return 0;
        } else {
            return end - begin + 1;
        }
    }
};