class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mn = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (k == j)
                        continue;
                    else
                        mn = min(mn, nums[i-1][k]);
                }
                nums[i][j] += mn;
            }
        }

        return *min_element(nums[n-1].begin(), nums[n-1].end());
    }
};