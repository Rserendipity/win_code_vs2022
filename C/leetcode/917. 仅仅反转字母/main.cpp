class Solution {
    bool isAlpha(char& ch) {
        return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
    }
public:
    string reverseOnlyLetters(string s) {
        int sz = s.size();
        int begin = 0, end = sz - 1;
        while (begin < end) {
            while (begin < sz && !isAlpha(s[begin]))
                begin++;
            while (end >= 0 && !isAlpha(s[end]))
                end--;
            
            if (begin < end)
                swap(s[begin], s[end]);
            begin++;
            end--;
        }
        return s;
    }
};