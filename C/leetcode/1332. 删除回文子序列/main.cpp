class Solution {
    bool isPrime(string& s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            if (s[begin++] != s[end--])
                return false;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0)
            return 0;
        else if (isPrime(s))
            return 1;
        else 
            return 2;
    }
};