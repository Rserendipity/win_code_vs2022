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
    int _findTilt(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }
        int left = _findTilt(root->left, ans);
        int right = _findTilt(root->right, ans);
        ans += abs(left - right);
        return root->val + left + right;
    }

    int findTilt(TreeNode* root) {
        int ans = 0;
        _findTilt(root, ans);
        return ans;
    }
};