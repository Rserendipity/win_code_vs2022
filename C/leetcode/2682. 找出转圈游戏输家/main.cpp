class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int> tmp(n), ans;
        int i = 0;
        int div = 1;
        while (true) {
            tmp[i]++;
            if (tmp[i] >= 2) {
                break;
            }
            i += div * k;
            i %= n;
            div++;
        }
        for (int i = 0; i < n; i++) {
            if (tmp[i] == 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};