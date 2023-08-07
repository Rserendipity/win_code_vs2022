class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            swap(s[begin], s[end]);
            begin++, end--;
        }
    }
};