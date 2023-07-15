class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto vec : edges) {
            int u = vec[0], v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> depth(n + 1), sz(n);
        function<int(int, int, int)> dfs = [&](int x, int fa, int d) {
            depth[d]++;
            sz[x] = 1;
            for (int y : adj[x]) {
                if (y == fa) continue;
                sz[x] += dfs(y, x, d + 1);
            }  
            return sz[x];
        };
        dfs(0, -1, 0);
        vector<int> ans(n);
        for (int d = 0; d <= n; d++) {
            ans[0] += d * depth[d];
        }
        function<void(int, int)> dfs2 = [&](int x, int fa) {
            if (fa != -1) {
                ans[x] = ans[fa] - sz[x] + sz[0] - sz[x];
            } 
            for (int y : adj[x]) {
                if (y == fa) continue;
                dfs2(y, x);
            }
        };
        dfs2(0, -1);
        return ans;
    }
};