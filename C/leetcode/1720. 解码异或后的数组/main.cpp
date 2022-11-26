#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int sz = encoded.size();
        vector<int> ans;
        ans.resize(sz + 1);
        ans[0] = first;
        for (int i = 1; i < sz + 1; i++)
        {
            ans[i] = (encoded[i - 1] ^ ans[i - 1]);
        }
        return ans;
    }
};
int main()
{

    return 0;
}
