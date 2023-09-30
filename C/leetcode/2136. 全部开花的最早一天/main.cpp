class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<int> id(plantTime.size());
        iota(id.begin(), id.end(), 0); // id[i] = i
        sort(id.begin(), id.end(), [&](int i, int j)
             { return growTime[i] > growTime[j]; });
        int ans = 0, days = 0;
        for (int i : id)
        {
            days += plantTime[i];               // 累加播种天数
            ans = max(ans, days + growTime[i]); // 再加上生长天数，就是这个种子的开花时间
        }
        return ans;
    }
};