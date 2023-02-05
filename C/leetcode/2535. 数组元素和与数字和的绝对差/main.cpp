class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0, val = 0;
        for (int n : nums) {
            sum += n;
            do {
                val += n % 10;
            } while (n /= 10);
        }
        return abs(sum - val);
    }
};