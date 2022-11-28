#define _CRT_SECURE_NO_WARNINGS 1
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
    TreeNode *construct(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;

        int index = l;
        for (int i = l; i <= r; i++)
        {
            if (nums[i] > nums[index])
                index = i;
        }

        TreeNode *newNode = new TreeNode(nums[index]);
        newNode->left = construct(nums, l, index - 1);
        newNode->right = construct(nums, index + 1, r);

        return newNode;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size() - 1);
    }
};
int main()
{

    return 0;
}
