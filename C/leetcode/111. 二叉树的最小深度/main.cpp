#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        
        if (l == 0 && r == 0) {
            return 1;
        } else if (l == 0) {
            return r + 1;
        } else if (r == 0) {
            return l + 1;
        } else {
            return min(l, r) + 1;
        }
    }
};
int main()
{

    return 0;
}
