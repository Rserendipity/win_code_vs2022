class Solution {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> chosen;
    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && chosen[i-1] == false)
                continue;
            if (chosen[i] == false) {
                chosen[i] = true;
                path.push_back(nums[i]);
                backtrack(nums);
                path.pop_back();
                chosen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        result.clear();
        path.clear();
        chosen.resize(nums.size(), false);
        backtrack(nums);
        return result;
    }
};