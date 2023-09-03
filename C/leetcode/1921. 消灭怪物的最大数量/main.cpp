class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; i++) {
            if (tmp[i] - i <= 0) {
                return i;
            }
        }
        return n;
    }
};