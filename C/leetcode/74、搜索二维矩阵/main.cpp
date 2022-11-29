#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int cor = matrix[0].size();

        int left = 0;
        int right = row - 1;
        int mid = (left + right) / 2;
        // 第一次二分，找到target所在的行
        while (left <= right)
        {
            if (matrix[mid][0] > target)
            {
                right = mid - 1;
            }
            else if (matrix[mid][cor - 1] < target)
            {
                left = mid + 1;
            }
            else
            {
                break;
            }
            mid = (left + right) / 2;
        }

        int index = mid;
        left = 0;
        right = cor - 1;
        mid = (left + right) / 2;
        // 第二次二分，找target
        while (left <= right)
        {
            if (matrix[index][mid] > target)
            {
                right = mid - 1;
            }
            else if (matrix[index][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                return true;
            }
            mid = (left + right) / 2;
        }
        return false;
    }
};
int main()
{

    return 0;
}
