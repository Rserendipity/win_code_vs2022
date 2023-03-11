class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto n : nums) {
            hash[n]++;
        }
        int ans = 0;
        for (auto& [_,v] : hash) {
            if (v >= 2) {
                v -= 1;
                ans += (1 + v) * v / 2;
            }
        }
        return ans;
    }
};