#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ַ�����ת
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

// �ַ������ң����ص�һ��ƥ����±�
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
// ����������������������������Ϊ  ����ֵ
// ���ظ�����������������������Ϊ -����ֵ
int reverNum(const char* str1, const char* str2) {
    int len = strlen(str1);
    // ���� ����len + 1���ȵĿռ�
    char* p = malloc(sizeof(char) * (2 * len + 1));
    // ��str1�������ݷŽ�ȥ
    for (int i = 0; i < len * 2; i++) {
        p[i] = str1[i % len];
    }
    // ������־
    p[len * 2] = '\0';
    
    // �������Ҳ���str2�Ӵ�
    int left = find(p, str2);

    // ��ת�����ַ���Ȼ���ٴβ���
    // ����൱��ԭ�ַ��������������
    reverStr(p);
    reverStr(str2);
    int right = find(p, str2);

    // �ͷſռ�
    free(p);
    // ����left��right��С����һ��
    // ����left�Ļ��������ģ�����������
    // ����reght�Ļ����ظ��ģ�����������
    return left < right ? left : -right;
}
int main() {
    char s1[] = "AABCD";
    char s2[] = "CDAAB";
    int ret = reverNum(s1, s2);
    if (ret < 0)
        printf("����%d\n", -ret);
    else
        printf("����%d\n", ret);
    return 0;
}