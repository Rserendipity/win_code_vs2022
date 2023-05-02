class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> hash;
        for (int n : nums)
            hash[n]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (hash[a] == hash[b]) 
                return a > b;
            else
                return hash[a] < hash[b];
        });
        return nums;
    }
};