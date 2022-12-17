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

    int sumOfMaxDepth(TreeNode* root, int depth) {
        if (root == nullptr) {
            return 0;
        }
        if (depth == 1) {
            return root->val;
        }
        return sumOfMaxDepth(root->left, depth - 1) + sumOfMaxDepth(root->right, depth - 1);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = deep(root);
        return sumOfMaxDepth(root, depth);
    }
};