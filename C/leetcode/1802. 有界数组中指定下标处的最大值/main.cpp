class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int ans = 1, l = index, r = index, sum = n;
        while (sum <= maxSum) {
            sum += r-l+1;
            ++ans;
            l = l == 0 ? 0 : l-1;
            r = r == n-1 ? n-1 : r+1;
            if (l == 0 && r == n-1 && n < maxSum-sum ) {
                return ans + (maxSum-sum)/n;
            }
        }
        return ans-1;
    }
};