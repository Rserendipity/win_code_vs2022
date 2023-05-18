class Solution {
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(vector<int>& candidates, int target, int sum, int start) {
        if (sum > target)
            return;
        
        if (sum == target) {
            ans.push_back(path);
        }

        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, target, sum, i);
            path.pop_back();
            sum -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return ans;
    }
};