//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <math.h>
//
//int main() 
//{
//    for (int i = 0; i < 100000; i++)
//    {
//        int n = 0;
//        int temp = i;
//        do
//        {
//            temp /= 10;
//            n++;
//        } while (temp);
//
//        int arr[6] = { 0 };
//        arr[0] = i % 10;
//        arr[1] = i / 10 % 10;
//        arr[2] = i / 100 % 10;
//        arr[3] = i / 1000 % 10;
//        arr[4] = i / 10000 % 10;
//        int sum = 0;
//        for (int j = 0; j < 5; j++)
//        {
//            sum += (int)pow(arr[j], n);
//        }
//        if (i == sum)
//        {
//            printf("%d ", i);
//        }
//    }
//    return 0;
//}