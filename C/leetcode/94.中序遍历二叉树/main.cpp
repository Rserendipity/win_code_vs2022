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

    // ������ջѭ��
    // ���ѭ����ᷢ�ֺͺ���ĵ�ѭ��������һ�����ظ�������Խ��кϲ���
    // �������������Ҫ�ں���ѭ���������һ���ж� while (p || !st.empty())������Ҳ������΢û��ôֱ�ۡ�����Բο�һ�°汾����
    // Ϊ�˷���ѧϰ���Ƿֿ�����Ϊ�ˡ��Ż�����������ѧϰ����ٿ��ǡ�
    while (p) {
        st.push(p);
        p = p->left;
    }

    while (!st.empty()) {
        auto node = st.top();
        st.pop();
        res.emplace_back(node->val);
        p = node->right;
        // һ������һ���ڵ㣬��������������ջ������
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
