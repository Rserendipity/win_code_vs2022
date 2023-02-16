class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int n : nums) {
            hash[n]++;
        }
        int cnt = 0;
        int leave = 0;
        for (auto& [_,v] : hash) {
            if (v % 2 == 0) {
                cnt += v / 2;
            } else {
                cnt += v / 2;
                leave++;
            }
        }
        return {cnt, leave};
    }
};