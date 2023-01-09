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
    int to_num(string& num) {
        int ret = 0;
        int sz = num.size() - 1;
        for (auto ch : num) {
            if (ch == '1') {
                ret += (1 << sz);
            }
            sz--;
        }
        return ret;
    }
    void sum(TreeNode* root, string& num, int& ans) {
        if (root == nullptr) {
            return;
        }
        num.push_back(root->val + '0');
        if (root->left == nullptr && root->right == nullptr) {
            ans += to_num(num);
            num.pop_back();
            return;
        }
        sum(root->left, num, ans);
        sum(root->right, num, ans);
        num.pop_back();
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        string num;
        int ans = 0;
        sum(root, num, ans);
        return ans;
    }
};