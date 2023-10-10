class Solution
{
    const int mod = 1e9 + 7;

public:
    int sumDistance(vector<int> &nums, string s, int d)
    {
        for (int i = 0; i < s.size(); i++)
        {
            nums[i] += (s[i] == 'R' ? d : -d);
        }
        ranges::sort(nums);
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            ans += (1ll * nums[i] - nums[i - 1]) * i % mod * (nums.size() - i) % mod;
        }
        return ans % mod;
    }
};