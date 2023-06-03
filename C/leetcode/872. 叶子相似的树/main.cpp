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
    vector<int> n1, n2;
    void dfs(TreeNode* root, vector<int>& n) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            n.push_back(root->val);
            return;
        }
        dfs(root->left, n);
        dfs(root->right, n);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        n1.clear();
        n2.clear();
        dfs(root1, n1);
        dfs(root2, n2);
        if (n1.size() != n2.size())
            return false;
        for (int i = 0; i < n1.size(); i++) {
            if (n1[i] != n2[i])
                return false;
        }
        return true;
    }
};