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
    unordered_map<int, int> hash;

    int lastorder(TreeNode* root) {
        if (root == nullptr) return 0;

        int left = lastorder(root->left);
        int right = lastorder(root->right);
        int sum = left + right + root->val;
        hash[sum] ++;
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        lastorder(root);

        int mx = -1;
        for (auto& [k,v] : hash) {
            mx = max(mx, v);
        }

        vector<int> result;
        for (auto& [k,v] : hash) {
            if (v == mx) {
                result.push_back(k);
            }
        }
        return result;
    }
};