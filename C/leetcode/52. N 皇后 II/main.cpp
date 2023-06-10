class Solution {
private:
    vector<vector<string>> result;
    // 递归函数参数
    void backtracking(int n, int row, vector<string>& chessboard){
       // 递归终止条件 - 行数等于n时表示达到叶子节点
       if(n == row){
           result.push_back(chessboard);
           return;
       }
       // 单次遍历逻辑
       for(int col = 0;col< n;col++){
           if(isValid(row, col, chessboard, n)){
               chessboard[row][col] = 'Q';
               backtracking(n,row+1,chessboard);
               chessboard[row][col] = '.';
           }
       }
    }
       // 判断是否合法
       bool isValid(int row, int col ,vector<string>& chessboard, int n){
           // 判断列
           for(int i = 0;i<row;i++){
               if(chessboard[i][col] == 'Q'){
                   return false;
               }
           }
           // 判断45度角
           for(int i = row - 1, j = col -1; i>=0 && j>=0; i--,j-- ){
               if(chessboard[i][j] == 'Q'){
                   return false;
               }
           }
           // 判断145度角
           for(int i = row -1, j = col + 1; i>=0 && j<n; i--,j++){
               if(chessboard[i][j] == 'Q'){
                   return false;
               }
           }
           return true;
       } 
public:
    int totalNQueens(int n) {
        result.clear();
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return result.size();
    }
};