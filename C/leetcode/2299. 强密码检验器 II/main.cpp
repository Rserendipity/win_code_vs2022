class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) {
            return false;
        }
        int flag = 0;
        char prev = '\0';
        for (int i = 0; i < password.size(); i++) {
            if (isdigit(password[i])) {
                flag |= 1; // 0000 0001
            } else if (islower(password[i])) {
                flag |= 2; // 0000 0010
            } else if (isupper(password[i])) {
                flag |= 4; // 0000 0100
            } else {
                flag |= 8; // 0000 1000
            }
            if (prev == password[i]) {
                return false;
            }
            prev = password[i];
        }
        return flag == 0xf; // 0000 1111
    }
};