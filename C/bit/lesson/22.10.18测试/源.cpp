#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void replaceSpace(char* str, int length) {
        char temp[100000] = { 0 };
        int count = 0;
        int index = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                strncat(temp, str + index, count);
                strcat(temp, "%20");
                index = i + 1;
                count = 0;
            }
            else {
                count++;
            }
        }
        strcat(temp, str + index); // 追加最后的出现的空格的剩余字符串
        strcpy(str, temp);
    }
};
int main() 
{
    char arr[100] = "We Are Happy";
    Solution s;
    cout << arr << endl;
    s.replaceSpace(arr, strlen(arr));
    cout << arr << endl;
    return 0;
}
