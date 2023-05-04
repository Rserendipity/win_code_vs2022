class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int& n : nums2)
            nums1.push_back(n);
        sort(nums1.begin(), nums1.end());

        int sz = nums1.size();
        if (sz % 2 == 1)
            return nums1[sz / 2];
        else
            return (nums1[sz/2 - 1] + nums1[nums1.size() / 2]) / 2.0;
    }
};