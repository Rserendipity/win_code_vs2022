class Solution {
    int _rob(vector<int>& nums, int begin, int end) {
        if (begin >= end) 
            return 0;
        
        int n = nums.size();
        vector<int> dp(n);
        dp[begin] = nums[begin];
        for (int i = begin + 1; i < end; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        return dp[end - 1];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0] + _rob(nums, 2, n-1), _rob(nums, 1, n));
    }
};