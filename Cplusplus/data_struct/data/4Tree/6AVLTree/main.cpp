#include "AVLTree.h"

// 右单选
void test1()
{
	AVLTree<int, int> t;
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	for (auto n : arr)
	{
		t.insert(make_pair(n, n*10));
	}
	t.InOrder();
}

// 左单选
void test2()
{
	AVLTree<int, int> t1;
	AVLTree<int, int> t2;
	// int arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto n : arr)
	{
		t1.insert(make_pair(n, n * 10));
	}

	cout << t1.is_banlance() << endl;

	//t.PreOrder();

	//t.InOrder();
}

int main()
{
	// test1();
	test2();

	return 0;
}