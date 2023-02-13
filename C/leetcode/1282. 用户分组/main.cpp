class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0 ; i < groupSizes.size(); i++) {
            hash[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto& [k, v] : hash) {
            int n = v.size() / k;
            int i = 0;
            while (n--) {
                vector<int> tmp;
                for (int j = 0; j < k; j++) {
                    tmp.push_back(v[i]);
                    i++;
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};