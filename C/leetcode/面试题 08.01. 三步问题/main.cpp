class Solution {
public:
    int waysToStep(int n) {
        vector<long long> v = {0,1,2,4};
        v.resize(n + 1);
        for (int i = 4; i <= n; i++) {
            v[i] = (v[i-1] + v[i-2] % 1000000007 + v[i-3] % 1000000007) % 1000000007;
        }
        return v.back() % 1000000007;
    }
};