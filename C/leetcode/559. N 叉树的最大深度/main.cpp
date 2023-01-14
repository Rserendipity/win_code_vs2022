/*
// Definition for a Node.
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
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        int max = 0;
        for (int i = 0; i < root->children.size(); i++) {
            int deep = maxDepth(root->children[i]);
            max = std::max(deep, max);
        }
        return max + 1;
    }
};