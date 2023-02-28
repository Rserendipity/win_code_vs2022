class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> hash;
        for (auto& v : items1) {
            hash[v[0]] += v[1];
        }
        for (auto& v : items2) {
            hash[v[0]] += v[1];
        }
        vector<vector<int>> ans;
        for (auto& [k, v] : hash) {
            ans.push_back({k, v});
        }
        return ans;
    }
};