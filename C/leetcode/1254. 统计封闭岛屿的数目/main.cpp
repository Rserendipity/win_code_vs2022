class Solution {
public:
    void DFS(vector<vector<int>>& grid,int i,int j,int& val)
    {
        if(i<0||i==grid.size()||j<0||j==grid[0].size())
        {
            val=0;
            return;
        }
        if(grid[i][j]!=0)return ;
        grid[i][j]=1;
        DFS(grid,i+1,j,val);
        DFS(grid,i-1,j,val);
        DFS(grid,i,j-1,val);
        DFS(grid,i,j+1,val);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==0) 
                {
                    int val=1;
                    DFS(grid,i,j,val);
                    count+=val;
                }
            }
        }
       return count;
    }
};