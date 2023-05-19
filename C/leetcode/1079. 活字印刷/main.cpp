class Solution {
    unordered_set<string> hash;
    vector<bool> chosen;
    string path;

    void dfs(string& tiles, int depth, int maxDepth) {
        if (depth == maxDepth) {
            hash.insert(path);
            // cout << path << endl;
            return;
        }

        for (int i = 0; i < tiles.size(); i++) {
            if (!chosen[i]) {
                chosen[i] = true;
                path.push_back(tiles[i]);
                dfs(tiles, depth + 1, maxDepth);
                path.pop_back();
                chosen[i] = false;
            }
        }
    }
public:
    int numTilePossibilities(string tiles) {
        chosen.resize(tiles.size(), false);
        for (int i = 0; i < tiles.size(); i++) {
            dfs(tiles, 0, i + 1);
        }
        return hash.size();
    }
};