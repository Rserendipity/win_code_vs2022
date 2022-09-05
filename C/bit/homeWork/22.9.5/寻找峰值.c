//#define _CRT_SECURE_NO_WARNINGS 1
//
//int findPeakElement(int* nums, int numsLen) {
//    // write code here
//    int letf = 0;
//    int right = numsLen - 1;
//    int mid = 0;
//    while (letf < right)
//    {
//        mid = (letf + right) / 2;
//        if (nums[mid] > nums[mid + 1])
//            right = mid;
//        else
//            letf = mid + 1;
//    }
//    return letf;
//}