#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int countConsistentStrings(string allowed, vector<string>& words) {
		int count = 0;
		int flag = 0;
		int hash[26] = { 0 };
		for (auto& ch : allowed) {
			hash[ch - 'a']++;
		}
		for (auto& s : words) {
			flag = 0;
			for (auto& ch : s) {
				if (hash[ch - 'a'] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				count++;
			}
		}
		return count;
	}
};
int main()
{

    system("pause");
    return 0;
}
