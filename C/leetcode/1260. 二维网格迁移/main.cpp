#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        k %= n * m;
        for (int i = 0; i < k; i++) {
            int save = grid[m - 1][n - 1];
            for (int j = m - 1; j >= 0; j--) {

                for (int t = n - 2; t >= 0; t--) {
                    grid[j][t + 1] = grid[j][t];
                }
                if (j > 0)
                    grid[j][0] = grid[j - 1][n - 1];
            }
            grid[0][0] = save;
        }
        return grid;
    }
};
int main()
{
    vector<vector<int>> grid = { {1,2,3} ,{4,5,6},{7,8,9} };
    Solution s;
    vector<vector<int>> ans = s.shiftGrid(grid, 1);
    for (auto& nums : ans) {
        for (auto& n : nums) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
