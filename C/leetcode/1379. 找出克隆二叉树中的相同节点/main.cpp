/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
    TreeNode *_find(TreeNode *root, TreeNode *target)
    {
        if (root == nullptr || root->val == target->val)
        {
            return root;
        }
        TreeNode *left = _find(root->left, target);
        if (left)
        {
            return left;
        }
        return _find(root->right, target);
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        return _find(cloned, target);
    }
};