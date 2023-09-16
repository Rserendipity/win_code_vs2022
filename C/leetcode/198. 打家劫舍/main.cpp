class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();

      vector<int> dp(n + 2);
      for (int i = 2; i < n + 2; i++) {
        // 偷当前的这个，那么最高就是 前天金额+当前金额
        // 不偷当前这个，那么最高就是 昨天的金额
        dp[i] = max(dp[i - 2] + nums[i - 2], dp[i - 1]);
      }
        return dp[n + 1];
    }
};