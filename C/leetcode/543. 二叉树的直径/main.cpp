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
    int deep(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = deep(root->left);
        int right = deep(root->right);
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftTree = diameterOfBinaryTree(root->left);
        int rightTree = diameterOfBinaryTree(root->right);
        int left = deep(root->left);
        int right = deep(root->right);
        return max({leftTree, rightTree, left + right});
    }
};