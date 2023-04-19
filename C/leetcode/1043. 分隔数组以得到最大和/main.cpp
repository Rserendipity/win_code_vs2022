class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            int max = 0;
            for(int j=i-1;j>=-1&&i-j<=k;--j) {
                max = std::max(max, arr[j+1]);
                dp[i] = std::max(dp[i], (j >= 0 ? dp[j] : 0) + (i - j) * max);
            }
        }
        return dp.back();
    }
};