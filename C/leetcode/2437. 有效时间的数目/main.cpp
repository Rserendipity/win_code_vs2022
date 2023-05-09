class Solution {
    int count(string t, int period) {
        int ans = 0;
        for (int i = 0; i < period; i++)
            if ((t[0] == '?' || i / 10 == t[0] - '0') &&
                (t[1] == '?' || i % 10 == t[1] - '0'))
                ans++;
        return ans;
    }
public:
    int countTime(string time) {
        return count(time.substr(0, 2), 24) * count(time.substr(3), 60);
    }
};