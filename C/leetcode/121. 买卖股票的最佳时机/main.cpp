class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT_MAX / 2;
        int ret = 0;
        for (auto& n : prices) {
            ret = max(ret, n - mn);
            mn = min(n, mn);
        }
        return ret;
    }
};
