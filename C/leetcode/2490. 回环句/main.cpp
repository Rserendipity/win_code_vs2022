class Solution {
public:
    bool isCircularSentence(string s) {
        stringstream ss(s);
        char back = s.back();
        while (ss >> s) {
            if (back != s.front())
                return false;
            back = s.back();
        }
        return true;
    }
};