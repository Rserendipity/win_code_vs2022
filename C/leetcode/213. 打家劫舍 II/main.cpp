class Solution {
    int _rob(vector<int>& nums, int begin, int end) {
      vector<int> dp(nums.size() + 2);
      for (int i = begin + 2; i < end + 2; i++) {
        dp[i] = max(dp[i - 2] + nums[i - 2], dp[i - 1]);
      }
        return dp[end + 1];
    }

public:
    int rob(vector<int>& nums) {
        // 偷 0 ~ n-2下标的
        // 偷 1 ~ n-1下标的
        // 取最大值
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // if (n == 2) return max(nums[0], nums[1]);

        // n > 2
        return max(_rob(nums, 0, n - 1), _rob(nums, 1, n));
    }
};