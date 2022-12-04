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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftHight = maxDepth(root->left) + 1;
        int righthight = maxDepth(root->right) + 1;

        return max(leftHight, righthight);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        int leftHight = maxDepth(root->left);
        int righthight = maxDepth(root->right);

        return abs(leftHight - righthight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
int main()
{

    return 0;
}
