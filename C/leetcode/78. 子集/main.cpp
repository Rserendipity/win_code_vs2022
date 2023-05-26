class Solution {
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int start) {
        result.push_back(path);
        if (start >= nums.size()) 
            return;

        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};