class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int i = 0, j = 0, n = nums.size();
        while (j < n) {
            if (j + 1 < n && nums[j + 1] - 1 == nums[j]) {
                j++;
            } else {
                string s;
                if (i != j) {
                    s += to_string(nums[i]);
                    s += "->";
                    s += to_string(nums[j]);
                } else {
                    s += to_string(nums[i]);
                }
                
                result.push_back(s);
                j++;
                i = j;
            }
        }
        return result;
    }
};