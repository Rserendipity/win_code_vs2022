#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.resize(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1);
            ans[i].front() = ans[i].back() = 1;
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] == 0) {
                    ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
                }
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}
