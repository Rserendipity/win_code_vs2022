class Solution {
public:
    int m, n, dir[4][2]={{-1,0}, {1,0}, {0,-1}, {0,1}};
    int DFS(vector<vector<int>>& G, int x, int y, int k){
        if(x<0 || x>=m || y<0 || y>=n || G[x][y]==-1)    return 0;
        if(G[x][y]==2)   return k==0;
        int s = 0;
        G[x][y] = -1;
        for(auto &d: dir)
            s += DFS(G, x+d[0], y+d[1], k-1);
        G[x][y] = 0;
        return s;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int k=1, x=0, y=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                }else if(grid[i][j]==0)
                    k++;
        return DFS(grid, x, y, k);
    }
};