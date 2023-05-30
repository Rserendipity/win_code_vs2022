class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int start, vector<bool>& chosen) {
        result.push_back(path);

        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && chosen[i-1] == false)
                continue;
            chosen[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, i + 1, chosen);
            path.pop_back();
            chosen[i] = false;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> chosen(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, chosen);
        return result;
    }
};