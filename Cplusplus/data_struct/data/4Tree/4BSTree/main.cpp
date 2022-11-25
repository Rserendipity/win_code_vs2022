#define _CRT_SECURE_NO_WARNINGS 1
#include "BSTree.h"

void test1()
{
    old::BSTree<int> tree;
    int arr[] = { 5,3,7,1,4,6,8,0,2,9 };
    for (auto n : arr)
    {
        tree.insert(n);
    }
    tree.inOrder();

    tree.findR(8);

    for (auto n : arr)
    {
        tree.erase(n);
        tree.inOrder();
    }
}

void test2()
{
    old::BSTree<int> tree;
    int arr[] = { 5,3,7,1,4,6,8,0,2,9 };
    for (auto n : arr)
    {
        tree.insertR(n);
    }
    tree.inOrder();

    for (auto n : arr)
    {
        if (tree.findR(n))
            tree.eraseR(n);
        tree.inOrder();
    }

}

void test3()
{
    KV::BSTree<int, std::string> t;
    t.insert(5, "555");
    t.insert(3, "333");
    t.insert(6, "666");
    t.insert(9, "999");

    t.inOrder();
}

void test4()
{
    KV::BSTree<std::string, int> t;
	std::string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "香蕉" };
    for (auto& s : arr) {
        auto it = t.find(s);
        if (it == nullptr)
            t.insert(s, 1);
        else
            it->val++;
    }
    t.inOrder();
}

int main()
{
    // test1();
    // test2();
    // test3();
    test4();

    return 0;
}
