class Solution {
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> chosen;

    void backtracking(vector<int>& candidates, int sum, int target, int start) {
        if (sum == target) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size() && target >= sum + candidates[i]; i++) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, sum, target, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        chosen.resize(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target, 0);
        return ans;
    }
};