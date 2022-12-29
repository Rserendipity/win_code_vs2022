class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> s1,s2,s3;
        unordered_map<int, int> hash;

        for (auto n : nums1) s1.insert(n);
        for (auto n : nums2) s2.insert(n);
        for (auto n : nums3) s3.insert(n);
        
        vector<int> ans;
        for (auto& k : s1) hash[k] ++;
        for (auto& k : s2) hash[k] ++;
        for (auto& k : s3) hash[k] ++;

        for (auto& kv : hash) {
            if (kv.second >= 2) {
                ans.push_back(kv.first);
            }
        }
        return ans;
    }
};