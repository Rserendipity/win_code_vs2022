//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <ctype.h>
//int myAtoi(char* s) {
//    int flag = 1;
//    double d1 = 0;
//    while (*s == ' ')
//    {
//        s++;
//    }
//    if (*s == '+')
//    {
//        flag = 1;
//        s++;
//    }
//    else if (*s == '-')
//    {
//        flag = -1;
//        s++;
//    }
//    if (!isdigit(*s))
//        return 0;
//    while (isdigit(*s) && *s != '\0')
//    {
//        d1 = d1 * 10 + (*s - '0');
//        s++;
//    }
//    d1 *= flag;
//    if (d1 > (int)0x7fffffff) // 0111 1111 1111 1111 1111 1111 1111 1111
//    {
//        return (int)0x7fffffff;
//    }
//    if (d1 < (int)0x80000000)
//    {
//        return (int)0x80000000;
//    }
//    return (int)d1;
//}
//int main() 
//{
//    char arr[] = "+-12";
//    printf("%d", myAtoi(arr));
//    return 0;
//}
