#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void _increasingBST(TreeNode *root, TreeNode *&pre)
    {
        if (root == nullptr)
        {
            return;
        }
        _increasingBST(root->left, pre);

        root->left = nullptr;
        if (pre)
        {
            pre->right = root;
        }
        pre = root;

        _increasingBST(root->right, pre);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *left = root;
        while (left && left->left)
        {
            left = left->left;
        }
        TreeNode *pre = nullptr;
        _increasingBST(root, pre);
        return left;
    }
};
int main()
{

    return 0;
}
