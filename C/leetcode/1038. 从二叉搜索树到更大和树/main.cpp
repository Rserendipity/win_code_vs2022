/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void _bstToGst(TreeNode* root, int& prev) {
        if (root == nullptr)
            return;
        _bstToGst(root->right, prev);
        root->val += prev;
        prev = root->val;
        _bstToGst(root->left, prev);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int prev = 0;
        _bstToGst(root, prev);
        return root;
    }
};