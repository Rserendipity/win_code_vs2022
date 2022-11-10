#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		map<int, int> hash;
		int sz = score.size();
		vector<string> ans;
		ans.resize(sz);
		for (int i = 0; i < sz; i++) {
			hash[score[i]] = i;
		}
		int count = 0;
		auto it = hash.rbegin();
		while (it != hash.rend()) {
			if (count == 0) {
				ans[it->second] = "Gold Medal";
			}
			else if (count == 1) {
				ans[it->second] = "Silver Medal";
			}
			else if (count == 2) {
				ans[it->second] = "Bronze Medal";
			}
			else {
				ans[it->second] = to_string(count + 1);
			}
			count++;
			it++;
		}
		return ans;
	}
};
int main()
{
	vector<int> nums = { 5,4,3,2,1 };
	Solution().findRelativeRanks(nums);
    system("pause");
    return 0;
}
