class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> G(8, vector<int>(8, 0));
        G[king[0]][king[1]] = 1; // 1 表示国王
        for(const auto& v : queens) {
            G[v[0]][v[1]] = 2; // 2 表示queen
        }
        for(int i = 1; i < 8; ++ i) { // +对角线
            if(king[0] + i < 0 || king[1] + i < 0 || king[0] + i >= 8 || king[1] + i >= 8)
                break;
            if(G[king[0] + i][king[1] + i] == 2) {
                G[king[0] + i][king[1] + i] = 3;
                break;
            }
        }
        for(int i = 1; i < 8; ++ i) { // -对角线
            if(king[0] - i < 0 || king[1] - i < 0 || king[0] - i >= 8 || king[1] - i >= 8)
                break;
            if(G[king[0] - i][king[1] - i] == 2) {
                G[king[0] - i][king[1] - i] = 3;
                break;
            }
        }

        for(int i = 1; i < 8; ++ i) { // +反对角线
            if(king[0] + i < 0 || king[1] - i < 0 || king[0] + i >= 8 || king[1] - i >= 8)
                break;
            if(G[king[0] + i][king[1] - i] == 2) {
                G[king[0] + i][king[1] - i] = 3;
                break;
            }
        }
        for(int i = 1; i < 8; ++ i) { // -反对角线
            if(king[0] - i < 0 || king[1] + i < 0 || king[0] - i >= 8 || king[1] + i >= 8)
                break;
            if(G[king[0] - i][king[1] + i] == 2) {
                G[king[0] - i][king[1] + i] = 3;
                break;
            }
        }

        for(int i = 1; i < 8; ++ i) { // +横
            if(king[0] < 0 || king[1] + i < 0 || king[0] >= 8 || king[1] + i >= 8)
                break;
            if(G[king[0]][king[1] + i] == 2) {
                G[king[0]][king[1] + i] = 3;
                break;
            }
        }
        for(int i = 1; i < 8; ++ i) { // -横
            if(king[0] < 0 || king[1] - i < 0 || king[0] >= 8 || king[1] - i >= 8)
                break;
            if(G[king[0]][king[1] - i] == 2) {
                G[king[0]][king[1] - i] = 3;
                break;
            }
        }

        for(int i = 1; i < 8; ++ i) { // +列
            if(king[0] + i < 0 || king[1]< 0 || king[0] + i >= 8 || king[1] >= 8)
                break;
            if(G[king[0] + i][king[1]] == 2) {
                G[king[0] + i][king[1]] = 3;
                break;
            }
        }
        for(int i = 1; i < 8; ++ i) { // -列
            if(king[0] - i < 0 || king[1] < 0 || king[0] - i >= 8 || king[1] >= 8)
                break;
            if(G[king[0] - i][king[1]] == 2) {
                G[king[0] - i][king[1]] = 3;
                break;
            }
        }
        vector<vector<int>> res;
        for(int i = 0; i < 8; ++ i)
            for(int j = 0; j < 8; ++ j)
                if(G[i][j] == 3)
                    res.pusah_back({i, j});
        return res;
    }
};
