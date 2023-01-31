class Solution
{
public:
    bool checkXMatrix(vector<vector<int>> &grid)
    {
        int sz = grid.size();
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                if (i + j + 1 == sz || i == j)
                {
                    if (grid[i][j] == 0)
                        return false;
                }
                else
                {
                    if (grid[i][j] != 0)
                        return false;
                }
            }
        }
        return true;
    }
};