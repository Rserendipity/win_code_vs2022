class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    arr[i][j] += min(arr[i-1][0], arr[i-1][1]);
                } else if (j == n - 1) {
                    arr[i][j] += min(arr[i-1][n-1], arr[i-1][n-2]);
                } else {
                    arr[i][j] += min({arr[i-1][j-1], arr[i-1][j], arr[i-1][j+1]});
                }
            }
        }

        int result = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (arr[n-1][i] < result) {
                result = arr[n-1][i];
            }
        }

        return result;
    }
};