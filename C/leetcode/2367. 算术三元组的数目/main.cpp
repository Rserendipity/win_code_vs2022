class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int sz = nums.size();
        int index = 0, ans = 0;
        while (index < sz) {
            int nextIndex = index + 1;
            while (nextIndex < sz) {
                // cout << (nums[nextIndex] - nums[index]) << endl;
                if (nums[nextIndex] - nums[index] < diff) {
                    nextIndex++;
                } else if (nums[nextIndex] - nums[index] > diff) {
                    break;
                } else {
                    // 找到第一个差值为diff的了，从当前下标的后一个，再开始找一个插值为diff的
                    int nnIndex = nextIndex + 1;
                    while (nnIndex < sz) {
                        if (nums[nnIndex] - nums[nextIndex] < diff) {
                            nnIndex++;
                        } else if (nums[nnIndex] - nums[nextIndex] > diff) {
                            break;
                        } else {
                            // 找到第二个了，返回
                            ans++;
                            break;
                        }
                    }
                    break;
                }
            }
            index++;
        }
        return ans;
    }
};