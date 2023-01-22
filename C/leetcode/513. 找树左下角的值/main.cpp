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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            ans = Q.front()->val;
            while (sz--) {
                TreeNode* tmp = Q.front();
                if (tmp->left) {
                    Q.push(tmp->left);
                }
                if (tmp->right) {
                    Q.push(tmp->right);
                }
                Q.pop();
            }
        }
        return ans;
    }
};