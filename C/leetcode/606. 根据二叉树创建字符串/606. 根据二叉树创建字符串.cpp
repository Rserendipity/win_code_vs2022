#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * */
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
    void _tree2str(TreeNode *root, string &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            ans += to_string(root->val);
            return;
        }
        if (root->left != nullptr && root->right == nullptr)
        {
            ans += to_string(root->val);
            ans += '(';
            _tree2str(root->left, ans);
            ans += ')';
            return;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            ans += to_string(root->val);
            ans += "()";
            ans += '(';
            _tree2str(root->right, ans);
            ans += ')';
            return;
        }

        ans += to_string(root->val);
        ans += '(';
        _tree2str(root->left, ans);
        ans += ')';

        ans += '(';
        _tree2str(root->right, ans);
        ans += ')';
    }
    string tree2str(TreeNode *root)
    {
        string ans;
        cout << to_string(-4);
        _tree2str(root, ans);
        return ans;
    }
};