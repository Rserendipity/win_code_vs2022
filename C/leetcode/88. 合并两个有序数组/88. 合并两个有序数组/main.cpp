#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int index = nums1.size() - 1;
		int end1 = m - 1;
		int end2 = n - 1;
		while (end1 >= 0 && end2 >= 0) {
			if (nums1[end1] > nums2[end2]) {
				nums1[index] = nums1[end1];
				index--;
				end1--;
			}
			else {
				nums1[index] = nums2[end2];
				index--;
				end2--;
			}
		}
		while (end2 >= 0)
		{
			nums1[index] = nums2[end2];
			index--;
			end2--;
		}
	}
};
int main()
{

    system("pause");
    return 0;
}
