class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        while (ans.size() < 32 && num != 0) {
            num *= 2;
            int tmp = (int)num;
            ans.push_back('0' + tmp);
            num -= tmp;
        }
        return num == 0 ? ans : "ERROR";
    }
};