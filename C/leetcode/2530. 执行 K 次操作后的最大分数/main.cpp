class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto &n : nums)
        {
            pq.push(n);
        }
        for (int i = 0; i < k; i++)
        {
            int n = pq.top();
            ans += n;
            pq.pop();
            pq.push((n + 2) / 3);
        }
        return ans;
    }
};