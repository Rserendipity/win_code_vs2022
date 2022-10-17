#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int count = 0;
        for (int i = 0; i < s.size() - k + 1; i++) {
            int div = atoi(s.substr(i, k).c_str());
            if (div == 0) {
                continue;
            }
            if (num % div == 0) {
                count++;
            }
        }
        return count;
    }
};
int main() 
{
    Solution s;
    cout << s.divisorSubstrings(240, 2);
    return 0;
}
