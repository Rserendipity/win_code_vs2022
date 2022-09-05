//#define _CRT_SECURE_NO_WARNINGS 1
//
//int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
//    // write code here
//    int* answer = (int*)calloc(sizeof(int) * numbersLen, 1);
//    *returnSize = 2;
//    for (int i = 0; i < numbersLen; i++)
//    {
//        if (numbers[i] > target)
//            continue;
//        for (int j = i + 1; j < numbersLen; j++)
//        {
//            if (numbers[i] + numbers[j] == target)
//            {
//                answer[0] = i + 1;
//                answer[1] = j + 1;
//                return answer;
//            }
//        }
//    }
//    return answer;
//}