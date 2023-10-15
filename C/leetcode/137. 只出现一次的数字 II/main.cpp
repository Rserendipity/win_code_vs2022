class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        for (auto &n : nums)
        {
            hash[n]++;
        }
        for (auto &[k, v] : hash)
        {
            if (v == 1)
                return k;
        }
        return -1;
    }
};