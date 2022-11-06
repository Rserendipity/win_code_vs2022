#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int sz = nums.size();
		int move = 0;
		int save = 0;
		while (move < sz) {
			if (nums[move] == 0) {
				move++;
			}
			else {
				swap(nums[save], nums[move]);
				save++;
				move++;
			}
		}
	}
};
int main()
{

    system("pause");
    return 0;
}
