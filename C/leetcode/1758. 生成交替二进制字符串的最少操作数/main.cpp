#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int sz = s.size();
        string cmp1;
        string cmp2;
        cmp1.resize(sz);
        cmp2.resize(sz);
        cmp1[0] = '0';
        cmp2[0] = '1';
        for (int i = 1; i < sz; i++)
        {
            if (cmp1[i - 1] == '0')
            {
                cmp1[i] = '1';
            }
            else
            {
                cmp1[i] = '0';
            }
            if (cmp2[i - 1] == '0')
            {
                cmp2[i] = '1';
            }
            else
            {
                cmp2[i] = '0';
            }
        }
        int cnt1 = 0;
        int cnt2 = 0;
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == cmp1[i])
            {
                cnt1++;
            }
            else
            {
                cnt2++;
            }
        }
        return min(cnt1, cnt2);
    }
};
int main()
{

    return 0;
}
