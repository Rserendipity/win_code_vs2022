/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void toStr(TreeNode* root, string& s) {
        if (root == nullptr) return;
        
        s += to_string(root->val);
        s += ' ';
        toStr(root->left, s);
        toStr(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        toStr(root, ans);
        return ans;
    }
    
    void insert(TreeNode* root, TreeNode*& prev, int val) {
        if (root == nullptr) {
            if (prev->val > val) {
                prev->left = new TreeNode(val);
            } else {
                prev->right = new TreeNode(val);
            }
        } else {
            prev = root;
            if (root->val > val) {
                insert(root->left, prev, val);
            } else {
                insert(root->right, prev, val);
            }
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode* root = nullptr;
        stringstream ss(s);
        while (ss >> s) {
            int val = stoi(s);
            if (root == nullptr) {
                root = new TreeNode(val);
            } else {
                TreeNode* prev = nullptr;
                insert(root, prev, val);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;