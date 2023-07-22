class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twi = 0;
        for (auto& n : bills) {
            if (n == 5) {
                five++;
            } else if (n == 10) {
                ten++;
                five--;
            } else if (n == 20) {
                if (ten) {
                    ten--;
                    five--;
                } else {
                    five -= 3;
                }
            }
            if (five < 0 || ten < 0 || twi < 0) {
                return false;
            }
        }
        return true;
    }
};