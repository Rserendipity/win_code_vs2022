class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> grid2(grid.size(), vector<int>(grid.size()));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                grid2[i][j] = grid[j][i];
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i] == grid2[j])
                    ans++;
        return ans;
    }
};