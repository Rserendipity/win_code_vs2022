class Solution {
    multiset<int> hash;

    void backtracking(vector<vector<int>>& mat, int depth, int sum, int maxDepth) {
        if (depth == maxDepth) {
            hash.insert(sum);
            // cout << sum << endl;
            return;
        }

        for (int i = 0; i < mat[depth].size(); i++) {
            sum += mat[depth][i];
            backtracking(mat, depth + 1, sum, maxDepth);
            sum -= mat[depth][i];
        }
    }

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        hash.clear();
        backtracking(mat, 0, 0, mat.size());
        auto it = hash.begin();
        for (int i = 0; i < k - 1; i++) {
            ++it;
        }
        return *it;
    }
};