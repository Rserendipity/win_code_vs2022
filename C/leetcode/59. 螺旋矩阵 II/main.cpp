class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int k = 1, i, j;
        // for (int i = 0; i < n / 2 + 1; i++) {
        //     // 从左至右
        //     for (int j = i; j < n - i; j++) {
        //         result[i][j] = cnt++;
        //     }
        //     // 从上至下
        //     for (int j = n - i - 1; j < n - i; j++) {
        //         result[i][j] = cnt++;
        //     }
        //     // 从右至左
        //     for (int j = n - i - 2; j >)
        //     // 从下到上
        // }
        for (i = 0; i < n; i++)
        {
            // 从左至右
            for (j = i; j < n - i; j++)
                result[i][j] = k++;

            // 从上到下
            for (j = i + 1; j < n - i; j++)
                result[j][n - 1 - i] = k++;

            // 从右至左
            for (j = n - i - 2; j >= i; j--)
                result[n - i - 1][j] = k++;

            // 从下至上
            for (j = n - i - 2; j > i; j--)
                result[j][i] = k++;
        }
        return result;
    }
};