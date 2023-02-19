class Solution {
public:
    string reverseLeftWords(string s, int n) {
        n %= s.size();
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};