class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> hash;
        for (auto& n : nums) {
            hash.insert(n);
        }
        int max = -1;
        for (auto& k : hash) {
            if (hash.count(-1*k) != 0) {
                max = std::max(max, abs(k));
            }
        }
        return max;
    }
};