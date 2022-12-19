/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void Caculate(TreeNode* root, unordered_set<int>& hash) {
        if (root == nullptr) {
            return ;
        }
        hash.insert(root->val);
        Caculate(root->left, hash);
        Caculate(root->right, hash);
    }
    
    int numColor(TreeNode* root) {
        unordered_set<int> hash;
        Caculate(root, hash);
        return hash.size();
    }
};
