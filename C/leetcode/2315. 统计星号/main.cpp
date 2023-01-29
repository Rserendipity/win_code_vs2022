class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool exist = false;
        for (char ch : s) {
            if (ch == '|' && exist) {
                exist = false;
            } else if (ch == '|' && !exist) {
                exist = true;
            } else if (ch == '*' && !exist) {
                cnt++;
            }
        }
        return cnt;
    }
};