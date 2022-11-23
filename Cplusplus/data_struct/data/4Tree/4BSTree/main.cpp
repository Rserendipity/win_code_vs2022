#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"

int main()
{
    BSTree<int> tree;
    int arr[] = { 6,4,2,5,7,1,3,5,9,8 };
    for (auto n : arr)
    {
        tree.insert(n);
    }
    tree.inOrder();

    cout << tree.find(10) << endl;

    return 0;
}
