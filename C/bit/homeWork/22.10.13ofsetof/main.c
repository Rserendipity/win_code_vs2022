//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//// #include <stdlib.h> // 注释掉库内的offsetof
//struct Temp {
//    int a;
//    char b;
//    int c;
//};
//
//#define offsetof(s, t) (int)(&((struct s*)0)->t)
//
//int main() 
//{
//    // 把零转换成struct Temp*类型，通过这个指针访问成员
//    // 再取出这个成员的地址，就是对0地址处的偏移量，即offsetof的功能
//    // 
//    // int a = (int)(&((struct Temp*)0)->b)
//    int a = offsetof(Temp, b);
//    printf("%d\n", a);
//
//    return 0;
//}
