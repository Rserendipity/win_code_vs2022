class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        auto ans = 0LL;
        int begin = 0, end = nums.size() - 1;
        while (begin <= end)
        {
            if (begin == end)
            {
                ans += nums[begin];
                break;
            }
            ans += stoi(to_string(nums[begin]) + to_string(nums[end]));
            begin++, end--;
        }
        return ans;
    }
};