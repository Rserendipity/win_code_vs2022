//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <ctype.h>
//#include <math.h>
//int main() {
//    int arr[40] = {0};
//    arr[0] = 0;
//    arr[1] = 1;
//    for (int i = 2; i < 40; i++) {
//        arr[i] = arr[i - 1] + arr[i - 2];
//    }
//    int input = 0;
//    int temp = 0;
//    while (scanf("%d", &input) == 1) {
//        int min = 10000000;
//        for (int i = 0; i < 40; i++) {
//            temp = abs(arr[i] - input);
//            if (temp < min) {
//                min = temp;
//            }
//            if (min == 0) {
//                break;
//            }
//        }
//        printf("%d\n", min);
//    }
//    return 0;
//}