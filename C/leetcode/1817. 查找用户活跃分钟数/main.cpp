class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> remove;
        vector<int> ans(k);
        // 去重
        for (auto& v : logs) {
            remove[v[0]].insert(v[1]);
        }
        // 计数
        for (auto& kv : remove) {
            ans[kv.second.size() - 1]++;
        }
        return ans;
    }
};