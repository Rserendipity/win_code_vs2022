class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string ans;
        while (ss >> title) {
            if (title.size() <= 2) {
                for (char& ch : title) {
                    if (ch >= 'A' && ch <= 'Z')
                        ans += ch - 'A' + 'a';
                    else
                        ans += ch;
                }
            } else {
                if (title[0] >= 'A' && title[0] <= 'Z')
                    ans += title[0];
                else
                    ans += title[0] - 'a' + 'A';
                for (int i = 1; i < title.size(); i++) {
                    if (title[i] >= 'A' && title[i] <= 'Z')
                        ans += title[i] - 'A' + 'a';
                    else
                        ans += title[i];
                }
            }
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};