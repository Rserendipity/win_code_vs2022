#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int sz = nums.size();
		if (sz == 1)
			return 1;

		int fast = 1;
		int slow = 0;
		while (fast < sz) {
			if (nums[fast] == nums[slow]) {
				fast++;
			}
			else {
				slow++;
				nums[slow] = nums[fast];
				fast++;
			}
		}
		return slow + 1;
	}
};
int main()
{
	vector<int> arr = { 0,0,1,1,1,1,4,4,5,6,6};

	Solution s;
	int sz = s.removeDuplicates(arr);
		
	for (int i = 0; i < sz; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
    return 0;
}
