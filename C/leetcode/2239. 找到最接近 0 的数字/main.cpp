class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int prev = -10000000;
        for (int i : nums) {
            if (abs(i) < abs(prev)) {
                prev = i;
            } else if (abs(i) == abs(prev)) {
                if (i > 0 && prev < 0) {
                    prev = i;
                }
            }
        }
        return prev;
    }
};