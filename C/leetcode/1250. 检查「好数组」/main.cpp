class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int ans = nums[0];
        for (int n : nums) {
            ans = gcd(n, ans);
            if (ans == 1) 
                return true;
        }
        return false;
    }
};