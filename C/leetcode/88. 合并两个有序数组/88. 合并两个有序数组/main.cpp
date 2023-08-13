class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = nums1.size() - 1;
        int end1 = m-1, end2 = n-1;
        while (end1 >= 0 && end2 >= 0) {
            if (nums1[end1] > nums2[end2]) {
                nums1[sz--] = nums1[end1--];
            } else {
                nums1[sz--] = nums2[end2--];
            }
        }
        while (end2 >= 0) {
            nums1[sz--] = nums2[end2--];
        }
    }
};