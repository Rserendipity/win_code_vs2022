class Solution {
public:
    int diagonalSum(vector<vector<int>>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i][i];
            sum += nums[n-1-i][i];
        }
        if (n % 2 == 0) {
            return sum;
        } else {
            return sum - nums[n/2][n/2];
        }
    }
};