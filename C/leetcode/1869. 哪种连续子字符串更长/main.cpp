class Solution {
public:
    bool checkZeroOnes(string s) {
        int max1 = 0, max0 = 0;
        int cnt1 = 0, cnt0 = 0;
        for (char ch : s) {
            if (ch == '1') {
                cnt1++;
                max0 = max(max0, cnt0);
                cnt0 = 0;
            } else {
                cnt0++;
                max1 = max(max1, cnt1);
                cnt1 = 0;
            }
        }
        max0 = max(max0, cnt0);
        max1 = max(max1, cnt1);
        return max1 > max0;
    }
};