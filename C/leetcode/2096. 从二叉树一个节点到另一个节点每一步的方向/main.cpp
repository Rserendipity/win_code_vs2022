/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    bool preorder(TreeNode* root, int target, vector<TreeNode*>& v) {
        if (root == nullptr) return false;
        
        v.push_back(root);
        if (root->val == target)
            return true;
        
        if (preorder(root->left, target, v))
            return true;

        if (preorder(root->right, target, v))
            return true;

        v.pop_back();
        return false;
    }
    
    TreeNode* getGrandparent(TreeNode* root, int start, int target) {
        vector<TreeNode*> v1, v2;
        preorder(root, start, v1);
        preorder(root, target, v2);

        int n = min(v1.size(), v2.size());
        int index = 0;
        
        // 找到第一次不同的节点，往前一个就是共同的根节点
        while (index < n && v1[index] == v2[index])
            index++;
        index--;

        return v1[index];
    }
    
    bool getPath(TreeNode* root, int val, string& s) {
        if (root == nullptr) return false;

        if (root->val == val) return true;

        s += 'L';
        if (getPath(root->left, val, s)) return true;
        s.pop_back();

        s += 'R';
        if (getPath(root->right, val, s)) return true;
        s.pop_back();

        return false;
    }
    
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        // 1.找最近的公共祖先
        TreeNode* grand = getGrandparent(root, startValue, destValue);
        
        // 2.找到祖先，从祖先找出去往的路径
        string sPath, tPath, ans;
        getPath(grand, startValue, sPath);
        getPath(grand, destValue, tPath);
        
        // 3.从叶节点到祖先
        for (auto& ch : sPath) {
            ans += 'U';
        }
        // 4.从祖先到叶节点
        for (auto& ch : tPath) {
            ans += ch;
        }

        return ans;
    }
};