class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int hash[11] = {0};
        for (auto& n : nums1) {
            hash[n]++;
        }
        for (auto& n : nums2) {
            hash[n]++;
        }
        
        for (int i = 0; i < 11; i++) {
            if (hash[i] >= 2) {
                return i;
            }
        }
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        return nums1[0] > nums2[0] 
            ? nums2[0] * 10 + nums1[0] 
            : nums1[0] * 10 + nums2[0];
    }
};