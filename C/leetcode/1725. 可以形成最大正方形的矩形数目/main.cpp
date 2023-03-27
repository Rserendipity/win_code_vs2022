class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int, int> hash;
        for (auto& v : rectangles) {
            hash[min(v[0], v[1])]++;
        }
        int ans = 0;
        int prev = INT_MIN;
        for (auto& [k,v] : hash) {
            if (k > prev) {
                prev = k;
                ans = v;
            }
        }
        return ans;
    }
};