class Solution {
    int _minMaxGame(vector<int>& nums, int sz) {
        if (sz == 1) {
            return nums[0];
        }
        int index = 0;
        int count = 0;
        for (int i = 0; i < sz; i += 2) {
            if (count % 2 == 0) {
                nums[index++] = min(nums[i], nums[i + 1]);
            } else {
                nums[index++] = max(nums[i], nums[i + 1]);
            }
            count++;
        }
        return _minMaxGame(nums, sz / 2);
    }
public:
    int minMaxGame(vector<int>& nums) {
        return _minMaxGame(nums, nums.size());
    }
};