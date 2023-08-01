class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int n=fronts.size(), mn=INT_MAX;
        unordered_set<int> S;
        for(int i=0;i<n;i++)
            if(fronts[i]==backs[i])
                S.emplace(fronts[i]);
        for(int i=0;i<n;i++){
            int x=fronts[i], y=backs[i];
            if(!S.count(x))
                mn = min(mn, x);
            if(!S.count(y))
                mn = min(mn, y);
        }
        return mn==INT_MAX ? 0 : mn;
    }
};