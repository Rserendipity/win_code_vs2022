class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size() - 1;
        return nums[sz]*nums[sz-1] - nums[0]*nums[1];
    }
};