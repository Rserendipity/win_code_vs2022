class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if (root)
            q.push(root);
        while (!q.empty()) {
            TreeNode* last = q.back();
            ans.push_back(last->val);
            int n = q.size();
            while (n--) {
                TreeNode* cur = q.front();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                q.pop();
            }
        }
        return ans;
    }
};