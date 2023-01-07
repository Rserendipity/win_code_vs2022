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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        while (!Q.empty()) {
            int n = Q.size();
            double sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* top = Q.front();
                sum += top->val;
                if (top->left) {
                    Q.push(top->left);
                }
                if (top->right) {
                    Q.push(top->right);
                }
                Q.pop();
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};