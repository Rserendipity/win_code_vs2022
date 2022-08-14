#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字符串反转
void reverStr(char* s) {
    int head = 0;
    int tail = strlen(s) - 1;
    while (head < tail) {
        char temp = s[head];
        s[head] = s[tail];
        s[tail] = temp;
        head++;
        tail--;
    }
}

// 字符串查找，返回第一次匹配的下标
int find(char* s, char* dest) {
    char* save = s;
    char* p = s;
    char* m = dest;
    while (*p != '\0') {
        p = s;
        m = dest;
        while (*p == *m && *m != '\0') {
            p++;
            m++;
        }
        if (*m == '\0')
            return s - save;
        s++;
    }
    return NULL;
}
// 返回正数，则是左旋，左旋次数为  返回值
// 返回负数，则是右旋，右旋次数为 -返回值
int reverNum(const char* str1, const char* str2) {
    int len = strlen(str1);
    // 开辟 两倍len + 1长度的空间
    char* p = malloc(sizeof(char) * (2 * len + 1));
    // 把str1拷贝两份放进去
    for (int i = 0; i < len * 2; i++) {
        p[i] = str1[i % len];
    }
    // 结束标志
    p[len * 2] = '\0';
    
    // 从左向右查找str2子串
    int left = find(p, str2);

    // 反转两个字符串然后再次查找
    // 这次相当于原字符串从右向左查找
    reverStr(p);
    reverStr(str2);
    int right = find(p, str2);

    // 释放空间
    free(p);
    // 返回left和right较小的哪一个
    // 返回left的话返回正的，标明是左旋
    // 返回reght的话返回负的，标明是右旋
    return left < right ? left : -right;
}
int main() {
    char s1[] = "AABCD";
    char s2[] = "CDAAB";
    int ret = reverNum(s1, s2);
    if (ret < 0)
        printf("右旋%d\n", -ret);
    else
        printf("左旋%d\n", ret);
    return 0;
}