#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
extern int guess(int num);
class Solution {
public:
    int guessNumber(int n) {
        int min = 0;
        int max = INT_MAX;
        int mid = min + (max - min) / 2;
        while (true) {
            int tmp = guess(mid);
            if (tmp == -1) { // mid 大于 要猜的数
                max = mid - 1;
            }
            else if (tmp == 1) {
                min = mid + 1;
            }
            else {
                break;
            }
            mid = min + (max - min) / 2;
        }
        return mid;
    }
};
int main()
{

    return 0;
}
