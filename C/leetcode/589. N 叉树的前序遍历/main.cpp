#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    void _preorder(Node* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            _preorder(root->children[i], v);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        _preorder(root, ans);
        return ans;
    }
};
int main()
{

    return 0;
}
