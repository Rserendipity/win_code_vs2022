#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // ≤ª∫œ¿Ì
        if (mat.size() * mat[0].size() != r * c) {
            return mat;
        }
        vector<vector<int>> ans;
        ans.resize(r);
        int count = 0;
        int index = -1;
        for (auto& arr : mat) {
            for (auto& n : arr) {
                if (count % c == 0) {
                    ++index;
                }
                ans[index].push_back(n);
                ++count;
            }
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> vv = { {1, 2},{3, 4},{5,6} };
    Solution().matrixReshape(vv, 2, 3);
    return 0;
}
