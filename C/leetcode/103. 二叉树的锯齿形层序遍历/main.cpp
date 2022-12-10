#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.*/
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while (!q.empty())
        {
            vector<int> tmp;
            int sz = q.size();
            while (sz--)
            {
                TreeNode *cur = q.front();
                if (cur)
                {
                    tmp.push_back(cur->val);
                    if (cur->left)
                    {
                        q.push(cur->left);
                    }
                    if (cur->right)
                    {
                        q.push(cur->right);
                    }
                }
                q.pop();
            }
            if (depth % 2 == 0)
            {
                reverse(tmp.begin(), tmp.end());
            }
            ans.push_back(tmp);
            depth++;
        }
        return ans;
    }
};
int main()
{

    return 0;
}