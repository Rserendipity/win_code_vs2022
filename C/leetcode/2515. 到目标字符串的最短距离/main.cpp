class Solution {
public:
    int closetTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        if (words[start] == target) {
            return 0;
        }
        int left = start - 1, right = start + 1;
        int lcnt = 1, rcnt = 1;
        while (left != start) {
            if (left < 0) {
                left = n - 1;
                continue;
            }
            if (words[left] != target) {
                lcnt++;
                left--;
            } else {
                break;
            }
        }
        // 没找到
        if (start == left) {
            return -1;
        }

        while (right != start && lcnt < n) {
            if (right >= n) {
                right = 0;
                continue;
            }
            if (words[right] != target) {
                rcnt++;
                right++;
            } else {
                break;
            }
        }
        return min(rcnt, lcnt);
    }
};