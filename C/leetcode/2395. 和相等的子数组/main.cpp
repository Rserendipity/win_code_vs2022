class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i = 0; i < nums.size() - 1; i++) {
            hash.insert(nums[i] + nums[i + 1]);
        }
        return hash.size() != nums.size() - 1;
    }
};