class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hash;
        for (auto& v : paths) {
            hash[v[0]]++;
            hash[v[1]]++;
        }

        for (auto& v : paths) {
            if (hash[v[1]] == 1) {
                return v[1];
            }
        }
        return "";
    }
};