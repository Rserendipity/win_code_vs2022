#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		int len = std::max(end1, end2) + 1;
		int carry = 0;
		int sum = 0;
		string ans;
		ans.resize(len + 1);

		while (end1 >= 0 || end2 >= 0 || carry != 0) {
			sum = carry;
			carry = 0;
			if (end1 >= 0) {
				sum += num1[end1] - '0';
				end1--;
			}
			if (end2 >= 0) {
				sum += num2[end2] - '0';
				end2--;
			}
			sum += carry;
			if (sum >= 10) {
				sum %= 10;
				carry = 1;
			}
			ans[len] = sum + '0';
			len--;
		}

		if (len == 0) {
			ans.erase(0, 1);
		}

		return ans;
	}
};

int main()
{

    system("pause");
    return 0;
}
