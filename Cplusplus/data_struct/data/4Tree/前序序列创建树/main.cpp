#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
TreeNode* GetTree(string& in, int& index)
{
    if (in[index] == '#') {
        index++;
        return nullptr;
    }
    TreeNode* newNode = new TreeNode(in[index++]);
    newNode->left = GetTree(in, index);
    newNode->right = GetTree(in, index);
    return newNode;
}
void inOrder(TreeNode* root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->val << " ";
        inOrder(root->right);
    }
}
int main()
{
    string input;
    int index = 0;
    while (cin >> input)
    {
        index = 0;
        TreeNode* tree = GetTree(input, index);
        inOrder(tree);
        cout << endl;
    }
    return 0;
}