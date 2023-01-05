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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        int depth = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            int prev = -1;
            while (sz--) {
                TreeNode* top = Q.front();
                if (depth % 2 == 0) {
                    if (top->val % 2 == 0) {
                        return false;
                    }
                    if (prev == -1) {
                        prev = top->val;
                    } else {
                        if (prev >= top->val) {
                            return false;
                        }
                        prev = top->val;
                    }
                } else {
                    if (top->val % 2 == 1) {
                        return false;
                    }
                    if (prev == -1) {
                        prev = top->val;
                    } else {
                        if (prev <= top->val) {
                            return false;
                        }
                        prev = top->val;
                    }
                }
                if (top->left) {
                    Q.push(top->left);
                }
                if (top->right) {
                    Q.push(top->right);
                }
                Q.pop();
            }
            depth++;
        }
        return true;
    }
};