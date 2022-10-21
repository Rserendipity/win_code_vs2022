#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    auto p = root;

    // 左链入栈循环
    // 这个循环你会发现和后面的的循环代码有一部分重复，你可以进行合并。
    // 但是这样你就需要在后面循环条件多加一个判断 while (p || !st.empty())，代码也会变得稍微没那么直观。你可以参考一下版本二。
    // 为了方便学习还是分开考虑为宜。优化的事情在你学习完后再考虑。
    while (p) {
        st.push(p);
        p = p->left;
    }

    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        res.emplace_back(node->val);
        p = node->right;
        // 一旦弹出一个节点，继续做“左链入栈”操作
        while (p) {
            st.push(p);
            p = p->left;
        }
    }
    return res;
}
int main()
{

    return 0;
}
