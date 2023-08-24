class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                row[i]++, col[j]++;
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans += grid[i][j] & (row[i] > 1 | col[j] > 1) ;
        return ans;
    }
};