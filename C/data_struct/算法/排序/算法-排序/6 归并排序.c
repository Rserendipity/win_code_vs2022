//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//void printArr(int* arr, int size)
//{
//    for (int i = 0; i < size; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");
//}
//
//void merge(int* arr, int* temp, int l, int m, int r)
//{
//    // ����λ��(�±�)
//    int l_pos = l;
//    
//    // �е�ֵ����һ�������Ұ벿�ֵĿ�ʼ!!!
//    int r_pos = m + 1; 
//
//    // ��ǰarr�е�Ԫ��Ӧ�÷���temp������
//    int pos = l;
//    
//    // ����Ĵ���,���߶�û�е���β
//    while (l_pos <= m && r_pos <= r)
//    {
//        // �ѵ�ǰ��С�Ĵ浽temp��
//        if (arr[l_pos] < arr[r_pos])
//            temp[pos++] = arr[l_pos++];
//        else
//            temp[pos++] = arr[r_pos++];
//    }
//
//    // ���Ұ벿�ֵ�β���Ժ�,ֱ�Ӹ������ʣ�µĵ�temp��
//    while (l_pos <= m)
//        temp[pos++] = arr[l_pos++];
//    // ����벿�ֵ�β���Ժ�,ֱ�Ӹ������ʣ�µĵ�temp��
//    while (r_pos <= r)
//        temp[pos++] = arr[r_pos++];
//
//    // ���ڵ�temp�е�Ԫ���Ѿ�����,ֱ�Ӹ��ƻ�arr��
//    while (l <= r)
//    {
//        arr[l] = temp[l];
//        l++;
//    }
//}
//
//void partition(int* arr, int* temp, int left, int right)
//{
//    // �ݹ�ֹͣ����
//    if (left < right)
//    {
//        // �����Ľ��л���,��Ϊ��������
//        int mid = (left + right) / 2;
//        // ��߽����з�
//        partition(arr, temp, left, mid);
//        // �ұ߽����з�
//        partition(arr, temp, mid + 1, right);
//        // �з�����Ժ���кϲ�
//        merge(arr, temp, left, mid, right);
//    }
//}
//
//void mergeSort(int* arr, int size)
//{
//    // ���ٿռ�,���ڴ�ŷ�����Ԫ��
//    int* temp = (int*)malloc(size * sizeof(int));
//    
//    // �ݹ���з�,Ȼ��ϲ�,�����ǹ鲢�ĺ���
//    partition(arr, temp, 0, size - 1);
//
//    // �ͷſռ�
//    free(temp);
//}
//
//int main()
//{
//    int arr[] = { 9, 5, 2, 7, 12, 4, 3, 1, 11 };
//    int size = sizeof(arr) / sizeof(arr[0]);
//    printArr(arr, size);
//
//    mergeSort(arr, size);
//
//    printArr(arr, size);
//	return 0;
//}