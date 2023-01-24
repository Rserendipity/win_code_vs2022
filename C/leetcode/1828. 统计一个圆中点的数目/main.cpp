class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int sz = queries.size();
        vector<int> ans(sz, 0);
        for (int i = 0; i < sz; i++) {
            for (auto& v : points) {
                if (pow(abs(queries[i][0] - v[0]), 2) 
                  + pow(abs(queries[i][1] - v[1]), 2) <= pow(queries[i][2], 2))
                    ans[i]++;
            }
        }
        return ans;
    }
};