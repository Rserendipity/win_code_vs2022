class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        for (char& ch : moves) {
            switch (ch) {
                case 'R': p.first++; break;
                case 'L': p.first--; break;
                case 'U': p.second++; break;
                case 'D': p.second--; break;
            }
        }
        return p.first == 0 && p.second == 0;
    }
};