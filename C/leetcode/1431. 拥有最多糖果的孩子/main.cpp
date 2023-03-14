class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size(), 0);
        int max = -1;
        for (int n : candies) {
            max = std::max(n, max);
        }
        for (int i = 0; i < candies.size(); i++) {
            ans[i] = candies[i] + extraCandies >= max;
        }
        return ans;
    }
};