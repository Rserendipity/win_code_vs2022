#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maxRepeating(string sequence, string word) {
		string temp = word;
		int count = 0;
		size_t fi = sequence.find(temp);
		while (fi != sequence.npos) {
			temp += word;
			count++;
			fi = sequence.find(temp);
		}
		return count;
	}
};
int main()
{
	Solution s;
	cout << s.maxRepeating("ababc", "ab") << endl;
	system("pause");
	return 0;
}
