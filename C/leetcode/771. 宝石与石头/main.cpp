class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int up[26] = {0};
        int low[26] = {0};
        int ans = 0;
        for (char ch : jewels) {
            if (isupper(ch))
                up[ch - 'A']++;
            else
                low[ch - 'a']++;
        }
        for (char ch : stones) {
            if (isupper(ch) && up[ch - 'A'] || islower(ch) && low[ch - 'a'])
                ans++;
        }
        return ans;
    }
};