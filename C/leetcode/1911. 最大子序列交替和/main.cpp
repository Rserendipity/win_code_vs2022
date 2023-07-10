class Solution
{
public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        long long x = nums[0];
        for (int i = 1; i < nums.size(); i++)
            x += max(nums[i] - nums[i - 1], 0);
        return x;
    }
};