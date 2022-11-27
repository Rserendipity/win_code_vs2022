#include <bits/stdc++.h>
using namespace std;
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr)
            return ans;
        
        dfs(root, ans, "");
        return ans;
    }
    void dfs(TreeNode* root, vector<string>& ans, string path) {
        path += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        if (root->left != nullptr)
            dfs(root->left, ans, path + "->");

        if (root->right != nullptr)
            dfs(root->right, ans, path + "->");
        
    }
};

int main() {
    
    return 0;
}