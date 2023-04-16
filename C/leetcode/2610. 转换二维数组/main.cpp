class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> hash;
        for (int n : nums) {
            hash[n]++;
        }
        int max = -1;
        for (auto& [k,v] : hash) {
            if (v > max)
                max = v;
        }
        ans.resize(max);
        for (auto& [k,v] : hash) {
            for (int i = 0; i < v; i++) {
                ans[i].push_back(k);
            }
        }
        return ans;
    }
};