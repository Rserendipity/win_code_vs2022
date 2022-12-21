class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans = 0;
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        while (v[0] != 0 || v[1] != 0) {
            v[1]--;
            v[2]--;
            ans++;
            sort(v.begin(), v.end());
        }
        return ans;
    }
};