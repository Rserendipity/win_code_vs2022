class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream ss(s);
        string tmp;
        int prev = 0;
        while (ss >> tmp) {
            if (isdigit(tmp[0])) {
                int now = stoi(tmp);
                if (now <= prev) {
                    return false;
                }
                prev = now;
            }
        }
        return true;
    }
};