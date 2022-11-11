#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr)
            return nullptr;
        if (root1 == nullptr && root2 != nullptr)
            return root2;
        if (root1 != nullptr && root2 == nullptr)
            return root1;

        TreeNode* newTree = root1;
        newTree->val += root2->val;
        newTree->left = mergeTrees(root1->left, root2->left);
        newTree->right = mergeTrees(root1->right, root2->right);
        return newTree;
    }
};
int main()
{

    return 0;
}
