class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        int mid = 0;
        while (begin <= end) {
            mid = begin + end >> 1;
            if (nums[mid] == target)
                return mid;
            // 如果中间值比最右侧小，那么右侧有序，再看 mid 处的值是否大于等于target
            // 满足的时候，就在右侧进行下一步的二分
            if (nums[mid] < nums[end]) {
                if (nums[mid] < target && target <= nums[end]) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (nums[begin] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};