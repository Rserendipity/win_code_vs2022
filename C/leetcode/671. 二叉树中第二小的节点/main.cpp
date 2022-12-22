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
    void perOrder(TreeNode* root, vector<int>& tmp) {
        if (root == nullptr) {
            return;
        }
        tmp.push_back(root->val);
        perOrder(root->left, tmp);
        perOrder(root->right, tmp);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> tmp;
        perOrder(root, tmp);
        sort(tmp.begin(), tmp.end());
        int ans = tmp[0];
        for (auto i : tmp) {
            if (ans != i) {
                ans = i;
                break;
            }
        }
        return ans != tmp[0] ? ans : -1;
    }
};