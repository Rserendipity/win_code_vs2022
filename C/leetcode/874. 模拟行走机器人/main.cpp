class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x=0, y=0, k=0, mx=0, d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        set<pair<int,int>> S;
        for(auto &v: obstacles)
            S.emplace(v[0], v[1]);
        for(auto &t: commands)
            if(t==-2)
                k = (k+3)%4;
            else if(t==-1)
                k = (k+1)%4;
            else
                for(int i=0;i<t;i++){
                    int xx=x+d[k][0], yy=y+d[k][1];
                    if(S.count({xx, yy}))   break;
                    mx = max(mx, xx*xx+yy*yy);
                    x = xx;
                    y = yy;
                }
        return mx;
    }
};