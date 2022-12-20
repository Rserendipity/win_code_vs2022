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
public:
    void _getMinimumDifference(TreeNode* root, TreeNode*& prev, size_t& sub) {
        if (root == nullptr) {
            return;
        }
        _getMinimumDifference(root->left, prev, sub);
        if (prev) {
            if (root->val - prev->val < sub) {
                sub = root->val - prev->val;
            }
        }
        prev = root;
        _getMinimumDifference(root->right, prev, sub);
    }

    int getMinimumDifference(TreeNode* root) {
        size_t sub = -1;
        TreeNode* prev = nullptr;
        _getMinimumDifference(root, prev, sub);
        return sub;
    }
};