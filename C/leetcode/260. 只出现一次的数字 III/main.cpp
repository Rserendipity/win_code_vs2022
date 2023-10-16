class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        for (auto &n : nums)
        {
            hash[n]++;
        }
        vector<int> ret;
        for (auto &[k, v] : hash)
        {
            if (v == 1)
                ret.push_back(k);
        }
        return ret;
    }
};