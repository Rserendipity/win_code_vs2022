class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        for (auto& v : grid) {
            sort(v.begin(), v.end());
        }
        for (int i = 0; i < grid[0].size(); i++) {
            int max = -1;
            for (int j = 0; j < grid.size(); j++) {
                max = std::max(max, grid[j][i]);
            }
            ans += max;
        }
        
        return ans;
    }
};