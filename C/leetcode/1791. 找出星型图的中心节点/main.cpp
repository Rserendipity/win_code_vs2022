class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> hash;
        for (auto& v : edges) {
            hash[v[0]]++;
            hash[v[1]]++;
        }
        for (auto&[k,v] : hash) {
            if (v == edges.size())
                return k;
        }
        return -1;
    }
};