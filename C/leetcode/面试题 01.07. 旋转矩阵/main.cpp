#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int row = matrix.size();
        for (int i = 0; i <= row - 1; i++) {
            for (int j = i + 1; j < row; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};