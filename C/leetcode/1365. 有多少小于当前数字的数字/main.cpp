class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int arr[101] = {0};
        vector<int> ans;

        for (int n : nums)
            arr[n]++;
        
        int cnt = 0;
        for (int i = 0; i < 101; i++) {
            int now = arr[i];
            arr[i] = cnt;
            cnt += now;
        }

        for (int n : nums)
            ans.push_back(arr[n]);
        
        return ans;
    }
};