class Solution {
    bool row(vector<vector<char>>& board, int val, int row) {
        int cnt = 0;
        if (val == '.')
            return true;
        for (int i = 0; i < 9; i++) {
            if (val == board[row][i]) 
                cnt++;
        }
        return cnt == 1;
    }
    bool cor(vector<vector<char>>& board, int val, int cor) {
        int cnt = 0;
        if (val == '.')
            return true;
        for (int i = 0; i < 9; i++) {
            if (val == board[i][cor]) 
                cnt++;
        }
        return cnt == 1;
    }
    bool group(vector<vector<char>>& board, int val, int gRow, int gCor) {
        int cnt = 0;
        if (val == '.')
            return true;
        for (int i = gRow*3; i < 3 + gRow*3; i++) {
            for (int j = gCor*3; j < 3 + gCor*3; j++) {
                if (val == board[i][j])
                    cnt++;
            }
        }
        return cnt == 1;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0 ; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (!row(board, board[i][j], i)
                || !cor(board, board[i][j], j)
                || !group(board, board[i][j], i/3, j/3))
                    return false;
                // if (!row(board, board[i][j], i)
                // || !cor(board, board[i][j], j))
                // {
                //     cout << board[i][j] << endl;
                //     cout << i << " " << j << endl;
                //     return false;
                // }
            }
        }
        return true;
    }
};