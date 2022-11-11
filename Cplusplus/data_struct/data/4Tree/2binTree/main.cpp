#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(char val) :data(val), left(nullptr), right(nullptr) {}
};

struct TreeNode* GetBinTree()
{
    struct TreeNode* node1 = new struct TreeNode('A');
    struct TreeNode* node2 = new struct TreeNode('B');
    struct TreeNode* node3 = new struct TreeNode('C');
    struct TreeNode* node4 = new struct TreeNode('D');
    struct TreeNode* node5 = new struct TreeNode('E');
    struct TreeNode* node6 = new struct TreeNode('F');
    struct TreeNode* node7 = new struct TreeNode('G');
    struct TreeNode* node8 = new struct TreeNode('H');

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->left = node6;
    node3->right = node7;
    node5->right = node8;
    return node1;
}

void preOrder(TreeNode* tree)
{
    if (tree) {
        cout << tree->data;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(TreeNode* tree)
{
    if (tree) {
        inOrder(tree->left);
        cout << tree->data;
        inOrder(tree->right);
    }
}

void lastOrder(TreeNode* tree)
{
    if (tree) {
        lastOrder(tree->left);
        lastOrder(tree->right);
        cout << tree->data;
    }
}

void test1()
{
    TreeNode* tree = GetBinTree();
    preOrder(tree);
    cout << endl;
    inOrder(tree);
    cout << endl;
    lastOrder(tree);
    cout << endl;
}

int BinTreeSize(TreeNode* root)
{
    return root == nullptr ? 0 : BinTreeSize(root->left) + BinTreeSize(root->right) + 1;
}

int BinTreeLeveSize(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    return BinTreeLeveSize(root->left) + BinTreeLeveSize(root->right);
}

int BinTreeLeveKSize(TreeNode* tree, int k)
{
    assert(k >= 1);

    if (tree == nullptr)
    {
        return 0;
    }
    else if (k == 1)
    {
        return 1;
    }
    else
    {
        return BinTreeLeveKSize(tree->left, k - 1) + BinTreeLeveKSize(tree->right, k - 1);
    }
}

int BinTreeDepth(TreeNode* tree)
{
    if (tree == nullptr)
        return 0;
    return max(BinTreeDepth(tree->left), BinTreeDepth(tree->right)) + 1;
}

int BinTreeMinDepth(TreeNode* tree)
{
    if (tree == nullptr)
        return 0;
    if (tree->left == nullptr || tree->right == nullptr)
        return 1;

    return min(BinTreeMinDepth(tree->left), BinTreeMinDepth(tree->right)) + 1;
}


TreeNode* BinTreeSearch(TreeNode* root, char val)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == val)
        return root;

    TreeNode* left = BinTreeSearch(root->left, val);
    if (left != nullptr)
        return left;

    TreeNode* right = BinTreeSearch(root->right, val);
    if (right != nullptr)
        return right;

    return nullptr;
}

void test2()
{
    TreeNode* tree = GetBinTree();

    cout << BinTreeSize(tree) << endl;
    cout << BinTreeLeveSize(tree) << endl;
    cout << BinTreeLeveKSize(tree, 3) << endl;
    cout << BinTreeDepth(tree) << endl;
    TreeNode* find = BinTreeSearch(tree, 'D');
    if (find != nullptr)
        cout << find->data << endl;
}

void test3()
{
    queue<TreeNode*> q;
    TreeNode* tree = GetBinTree();

    q.push(tree);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }
    cout << endl;
}

bool BinTreeComplite(TreeNode* root)
{
    if (root == nullptr)
        return true;

    queue<TreeNode*> q;
    q.push(root);

    // 对头元素非空，把自己弹掉，左右孩子入队列
    while (q.front() != nullptr)
    {
        TreeNode* node = q.front();
        q.pop();
        q.push(node->left);
        q.push(node->right);
    }

    // 出队列的时候有非空的，则为 false
    while (!q.empty())
    {
        if (q.front() != nullptr)
            return false;
        q.pop();
    }
    return true;
}

void test4()
{
    TreeNode* tree = GetBinTree();
    cout << BinTreeComplite(tree) << endl;
}

void test5()
{
    TreeNode* tree = GetBinTree();
    int depth = BinTreeDepth(tree);
    int mindepth = BinTreeMinDepth(tree);
    preOrder(tree);
    cout << endl;
    inOrder(tree);
    cout << endl;

    cout << depth - mindepth << endl;
}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}
