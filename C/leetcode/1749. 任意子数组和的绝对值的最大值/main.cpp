class Solution {
public:
    int maxAbsoluteSum(vector<int>& a) {
        int dp = 0, mx = 0, mn = 0;
        
        for(int x : a){
            dp = max(dp, 0) + x;
            mx = max(mx, dp);
        }
        
        dp = 0;
        for(int x : a){
            dp = min(dp, 0) + x;
            mn = min(mn, dp);
        }
        
        return max(mx, -mn);
    }
};