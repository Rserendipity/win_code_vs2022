class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0, y = 0;
        int target_x = 0, target_y = 0;
        for (char ch : target) {
            while (true) {
                target_y = (ch - 'a') % 5;
                target_x = (ch - 'a' - target_y) / 5;
                if (y - target_y > 0) {
                    ans += 'L';
                    y--;
                } else if (x - target_x > 0) {
                    ans += 'U';
                    x--;
                } else if (y - target_y < 0) {
                    ans += 'R';
                    y++;
                } else if (x - target_x < 0) {
                    ans += 'D';
                    x++;
                }  else {
                    ans += '!';
                    break;
                }
            }
        } 
        return ans;
    }
};