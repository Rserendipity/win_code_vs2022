#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            // nothing to do
        }
        else {
            nums[index] = nums[i];
            index++;
            count++;
        }
    }
    return count;
}
int main() 
{
    const int x = 10;

    printf("%d", x);
    return 0;
}
