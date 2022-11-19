#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        map<int, int> hash;
        for (int i = 0; i < points.size(); i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int distance = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (hash[distance] == 0) {
                    hash[distance] = i + 1;
                }
            }
        }
        auto it = hash.begin();
        return hash.empty() ? -1 : it->second - 1;
    }
};
int main()
{
    vector<vector<int>> vv = { {1,2},{3,1},{2,4},{2,3},{4,4} };

    Solution().nearestValidPoint(3, 4, vv);

    return 0;
}
