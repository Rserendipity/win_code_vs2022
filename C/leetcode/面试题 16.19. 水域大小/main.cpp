class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] == 0){
                    int size = dfs(land, i, j);
                    res.push_back(size);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    int  dfs(vector<vector<int>> & land, int i, int j){
        if(i < 0 || j < 0 || i >= land.size() || j >= land[0].size()) return 0;
        if(land[i][j] != 0) return 0;
        land[i][j] = 1; // mark visited.
        int size = 1;
        for(auto & d: directions){
            size += dfs(land, i+d[0], j+d[1]);
        }
        return size;
    }
private:
    const vector<vector<int>> directions = 
    {{0, 1},{0, -1},{1, 0},{-1, 0},{-1, -1},{-1, 1},{1, -1},{1, 1}};
};