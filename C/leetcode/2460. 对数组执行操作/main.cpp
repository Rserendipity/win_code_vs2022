class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        // 执行第一步操作
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // 把0往后移动
        int begin = 0, end = 0;
        while (end < nums.size()) {
            while (begin < nums.size() && nums[begin] != 0)
                begin++;
            if (end == 0)
                end = begin;
            while (end < nums.size() && nums[end] == 0)
                end++;
            if (end < nums.size())
                swap(nums[begin], nums[end]);
            begin++, end++;
        }
        return nums;
    }
};