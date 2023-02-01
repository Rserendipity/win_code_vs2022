class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> hash;
        char tmp = 'a';
        for (char k : key) {
            if (k != ' ')
                if (!hash[k]) {
                    hash[k] = tmp++;
                }
        }
        string ans;
        for (char m : message) {
            if (m == ' ') 
                ans += ' ';
            else
                ans += hash[m];
        }
        return ans;
    }
};