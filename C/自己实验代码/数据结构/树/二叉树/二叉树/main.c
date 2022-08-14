#define _CRT_SECURE_NO_WARNINGS 1
#include "binTree.h"



int main()
{
	Tree* tree = createTree("ABD##E##CF#G###");

	// 前中后遍历
	preOrder(tree);
	inOrder(tree);
	postOrder(tree);
	// 层序遍历
	levelOrder(tree);

	// 统计深度,叶子数,结点数
	printf("max depth = %d\n", depth(tree));
	printf("leaf num = %d\n", leaf(tree));
	printf("node num = %d\n", tree->nodeNum);

	int maxIndex = 0;
	int secIndex = 0;
	int arr[] = { 10,2,3,6,2,8,9 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		if (arr[maxIndex] < arr[i]) {
			// 把当前的最大值下表给到次大值
			// 然后再更新最大值下标
			secIndex = maxIndex;
			maxIndex = i;
		}
	}
	// 第一个元素就是最大值的时候就再次寻找剩下的最大值
	if (maxIndex == 0) {
		secIndex = 1;
		for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++) {
			if (arr[secIndex] < arr[i])
				secIndex = i;
		}
	}


	return 0;
}