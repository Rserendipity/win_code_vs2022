//#define _CRT_SECURE_NO_WARNINGS 1
//
///**
// * Note: The returned array must be malloced, assume caller calls free().
// */
//int* masterMind(char* solution, char* guess, int* returnSize) {
//    static int answer[2] = { 0 };
//    *returnSize = 2;
//    int arr1[4] = { 0 };
//    int arr2[4] = { 0 };
//    for (int i = 0; i < 2; i++)
//    {
//        answer[i] = 0;
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        if (solution[i] == guess[i])
//        {
//            answer[0] += 1;
//        }
//        else
//        {
//            switch (solution[i])
//            {
//            case 'R': arr1[0]++; break;
//            case 'G': arr1[1]++; break;
//            case 'B': arr1[2]++; break;
//            case 'Y': arr1[3]++; break;
//            }
//            switch (guess[i])
//            {
//            case 'R': arr2[0]++; break;
//            case 'G': arr2[1]++; break;
//            case 'B': arr2[2]++; break;
//            case 'Y': arr2[3]++; break;
//            }
//        }
//
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        if (arr1[i] != 0 && arr2[i] != 0)
//        {
//            answer[1] += fmin(arr1[i], arr2[i]);
//        }
//    }
//    return answer;
//}