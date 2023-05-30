class Solution {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> chosen;

    void backtracking(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (chosen[i] == false) {
                chosen[i] = true;
                path.push_back(nums[i]);
                backtracking(nums);
                path.pop_back();
                chosen[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        chosen.clear();
        chosen.resize(nums.size(), false);
        backtracking(nums);
        return result;
    }
};