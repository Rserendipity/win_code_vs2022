#define _CRT_SECURE_NO_WARNINGS 1
#include "binTree.h"



int main()
{
	Tree* tree = createTree("ABD##E##CF#G###");

	// ǰ�к����
	preOrder(tree);
	inOrder(tree);
	postOrder(tree);
	// �������
	levelOrder(tree);

	// ͳ�����,Ҷ����,�����
	printf("max depth = %d\n", depth(tree));
	printf("leaf num = %d\n", leaf(tree));
	printf("node num = %d\n", tree->nodeNum);

	int maxIndex = 0;
	int secIndex = 0;
	int arr[] = { 10,2,3,6,2,8,9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[maxIndex] < arr[i]) {
			// �ѵ�ǰ�����ֵ�±�����δ�ֵ
			// Ȼ���ٸ������ֵ�±�
			secIndex = maxIndex;
			maxIndex = i;
		}
	}
	// ��һ��Ԫ�ؾ������ֵ��ʱ����ٴ�Ѱ��ʣ�µ����ֵ
	if (maxIndex == 0) {
		secIndex = 1;
		for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
			if (arr[secIndex] < arr[i])
				secIndex = i;
		}
	}


	return 0;
}