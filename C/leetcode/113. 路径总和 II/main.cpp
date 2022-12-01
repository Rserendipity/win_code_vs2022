#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void dfs(TreeNode *root, vector<vector<int>> &ans, vector<int> &tmp, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }
        tmp.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && root->val == targetSum)
        {
            ans.push_back(tmp);
        }
        dfs(root->left, ans, tmp, targetSum - root->val);
        dfs(root->right, ans, tmp, targetSum - root->val);
        tmp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(root, ans, tmp, targetSum);
        return ans;
    }
};
int main()
{

    return 0;
}
