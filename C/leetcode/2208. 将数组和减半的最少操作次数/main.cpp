class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum = 0;
        for (auto& n : nums) {
            sum += n;
        }
        sum /= 2.0;
        priority_queue<double> pq(nums.begin(), nums.end());
        double sum2 = 0;
        int cnt = 0;

        while (sum2 < sum) {
            double top = pq.top();
            sum2 += top / 2.0;
            pq.pop();
            pq.push(top / 2.0);
            cnt++;
        }
        return cnt;
    }
};