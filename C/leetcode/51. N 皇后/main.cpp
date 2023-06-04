class Solution {
    vector<vector<string>> result;
    void backtracking(int n, int depth, vector<string>& v) {
        if (n == depth) {
            result.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(depth, i, v, n)) {
                v[depth][i] = 'Q';
                backtracking(n, depth + 1, v);
                v[depth][i] = '.';
            }
        }
    }
    bool isValid(int row, int col, vector<string>& chessboard, int n) {
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (chessboard[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chessboard[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}
public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<string> v(n, string(n, '.'));
        backtracking(n, 0, v);
        return result;
    }
};