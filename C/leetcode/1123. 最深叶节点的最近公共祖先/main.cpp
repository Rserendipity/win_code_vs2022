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
    int hight(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(hight(root->left), hight(root->right)) + 1;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == nullptr) return nullptr;

        int l = hight(root->left), r = hight(root->right);
        if (l == r) return root;
        else if (l < r) return lcaDeepestLeaves(root->right);
        else return lcaDeepestLeaves(root->left);
    }
};