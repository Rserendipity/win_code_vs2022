//#include <stdio.h>
//
//void main()
//{
//    volatile int i = 10;
//    int a = i;
//
//    printf("i = %d\n", a);
//
//    // �������������þ��Ǹı��ڴ��� i ��ֵ
//    // �����ֲ��ñ�����֪��
//    __asm {
//        mov dword ptr[ebp - 4], 20h
//    }
//    scanf("a");
//    int b = i;
//    printf("i = %d\n", b);
//}