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
    TreeNode* expandBinaryTree(TreeNode* root) {
        if (root == nullptr) 
            return nullptr;
        if (root->left == nullptr && root->right == nullptr) 
            return nullptr;
        if (root->left) {
            TreeNode* insert_L = new TreeNode(-1);
            insert_L->left = root->left;
            expandBinaryTree(root->left);
            root->left = insert_L;
        }
        if (root->right) {
            TreeNode* insert_R = new TreeNode(-1);
            insert_R->right = root->right;
            expandBinaryTree(root->right);
            root->right = insert_R;
        }
        return root;
    }
};