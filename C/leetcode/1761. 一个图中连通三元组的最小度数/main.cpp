class Solution {
public:
  int minTrioDegree(int n, vector<vector<int>> &edges) {
    int G[401][401] = {0}, d[401] = {0}, mn = INT_MAX;
    for (auto &e : edges) {
      int x = e[0], y = e[1];
      G[x][y] = G[y][x] = 1;
      d[x]++;
      d[y]++;
    }
    for (int i = 1; i <= n; i++)
      for (int j = i + 1; j <= n; j++)
        for (int k = j + 1; k <= n; k++)
          if (G[i][j] && G[j][k] && G[i][k])
            mn = min(mn, d[i] + d[j] + d[k] - 6);
    return mn == INT_MAX ? -1 : mn;
  }
};