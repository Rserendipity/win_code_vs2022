class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if (income == 0) {
            return 0;
        }
        int prev = 0;
        double ans = 0;
        for (auto& v : brackets) {
            if (v[0] > income) {
                ans += (income - (double)prev) * (v[1] / 100.0);
                break;
            } else {
                if (v[1] == 0) {
                    prev = v[0];
                    continue;
                }
                ans += (v[0] - (double)prev) * (v[1] / 100.0);
                prev = v[0];
            }
        }
        return ans;
    }
};