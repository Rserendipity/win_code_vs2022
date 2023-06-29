class Solution {
    int m = 0;
    int n = 0;
    vector<vector<bool>> chosen;
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        chosen.resize(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int depth) {
        if (depth == word.size())
            return true;

        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (chosen[i][j] || board[i][j] != word[depth])
            return false;

        chosen[i][j] = true;

        bool ret = dfs(board, word, i - 1, j, depth + 1) ||
                   dfs(board, word, i + 1, j, depth + 1) ||
                   dfs(board, word, i, j - 1, depth + 1) ||
                   dfs(board, word, i, j + 1, depth + 1);

        chosen[i][j] = false;

        return ret;
    }
};