class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin < end) {
            int sum = nums[begin] + nums[end];
            if (begin < end && sum < target) {
                begin++;
            } else if (begin < end && sum > target) {
                end--;
            } else {
                return {nums[begin], nums[end]};
            }
        }
        return {-1, -1};
    }
};