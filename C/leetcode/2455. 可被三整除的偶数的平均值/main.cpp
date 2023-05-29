class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0;
        int cnt = 0;
        for (auto& n : nums) {
            if (n % 3 == 0 && n % 2 == 0) {
                sum += n;
                cnt++;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};