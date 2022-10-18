#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
int main()
{

    for (int i = 1; i <= 1000; i++) {
        printf("[");
        for (int j = 0; j <= i / 10; j++) {
            printf("=");
        }
        printf(">");
        for (int j = 0; j <= 100 - i / 10 - 1; j++) {
            printf(" ");
        }
        printf("][%d%%]", i / 10);
        if (i % 30 <= 10) {
            printf("[\\]\r");
        }
        else if (i % 30 <= 20) {
            printf("[|]\r");
        }
        else {
            printf("[/]\r");
        }
        fflush(stdout);
        Sleep(100);
    }


    return 0;
}

