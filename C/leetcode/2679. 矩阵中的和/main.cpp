class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int sum = 0;
        for (auto& v : nums) {
            sort(v.begin(), v.end());
        }
        // 列
        for (int i = 0; i < n; i++) {
            int max = INT_MIN;
            for (int j = 0; j < m; j++) {
                max = std::max(max, nums[j][i]);
            }
            sum += max;
        }
        return sum;
    }
};