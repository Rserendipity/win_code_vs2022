static const int N = 1e4+5;
static int arr[N];
static int dp[N];
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        memset(arr, 0, sizeof arr);
        memset(arr, 0, sizeof dp);
        for (int i = 0; i < nums.size(); i++) {
            arr[nums[i]]++;
        }
        for (int i = 0; i < N; i++) {
            arr[i] *= i;
        }

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        for (int i = 2; i < N; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        return dp[N-1];
    }
};