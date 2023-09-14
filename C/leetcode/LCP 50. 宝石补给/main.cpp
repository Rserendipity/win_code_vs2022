class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for (auto& v : operations) {
            int t = gem[v[0]] / 2;
            gem[v[1]] += t;
            gem[v[0]] -= t;
        }
        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};