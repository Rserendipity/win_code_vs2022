class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int hash[26] = {0};
        memset(hash, -1, 26 * sizeof(int));
        for (int i = 0; i < s.size(); i++) {
            if (hash[s[i] - 'a'] == -1)
                hash[s[i] - 'a'] = i;
            else 
                if (distance[s[i] - 'a'] != i - hash[s[i] - 'a'] - 1)
                    return false;
        }
        return true;
    }
};