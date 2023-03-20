class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for (auto& str: bank) {
            int now = 0;
            for (char ch : str) {
                if (ch == '1')
                    now++;
            }
            if (now == 0)
                continue;
            if (prev)
                ans += now * prev;
            prev = now;
        }
        return ans;
    }
};