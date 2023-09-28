class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> s;
        for (auto &x : flowers)
        {
            s.push_back(x[0]);
            s.push_back(x[1]);
        }
        for (auto x : people)
            s.push_back(x);
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end()); // 去重
        int m = s.size();
        vector<int> a(m + 1);
        for (auto &x : flowers)
        { // 差分数组实现"区间加"
            a[lower_bound(s.begin(), s.end(), x[0]) - s.begin()]++;
            a[lower_bound(s.begin(), s.end(), x[1]) - s.begin() + 1]--;
        }
        partial_sum(a.begin(), a.end(), a.begin()); // 差分数组上的前缀和即为各个日期在花期内的花的数目
        vector<int> res;
        for (auto x : people)
            res.push_back(a[lower_bound(s.begin(), s.end(), x) - s.begin()]);
        return res;
    }
};
