class Solution {
    int result = 0;
    vector<int> path;

    void backtracking(vector<int>& nums, int begin) {
        if (path.size() == 3) {
            if (path[0] != path[1] && path[1] != path[2] && path[0] != path[2])
                result++;
            return;
        }

        for (int i = begin; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    int unequalTriplets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
};