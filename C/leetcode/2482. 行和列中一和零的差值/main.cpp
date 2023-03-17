class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(grid);
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i] += grid[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                col[i] += grid[j][i];
            }
        }

        // cout << row[0] << endl;
        // cout << col[0] << endl;
        // cout << (n - row[0]) << endl;
        // cout << (m - col[0]) << endl;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = row[i] + col[j] - (n - row[i]) - (m - col[j]);
            }
        }
        return ans;
    }
};