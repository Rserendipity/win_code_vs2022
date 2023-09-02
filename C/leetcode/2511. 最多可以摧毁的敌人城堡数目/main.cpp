class Solution {
public:
    int captureForts(vector<int>& nums) {
        int ans = 0, pre = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1 || nums[i] == -1) {
                if (pre >= 0 && nums[i] != nums[pre]) {
                    ans = max(ans, i - pre - 1);
                }
                pre = i;
            }
        }
        return ans;
    }
};