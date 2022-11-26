#define _CRT_SECURE_NO_WARNINGS 1
#include "NoRtree.h"
#include <stack>
#include <cassert>

/// <summary>
/// 非递归的前序
/// </summary>
void test1()
{
    int arr[] = {6,1,8,3,2,4,9};
    old::BSTree<int> t;
    for (auto n : arr) 
    {
        t.insert(n);
    }
    // t.inOrder();



    std::stack<const old::BSTreeNode<int>*> st;
    auto root = t.GetRoot();

    auto cur = root;

    while (cur || !st.empty())
    {
        while (cur != nullptr)
        {
            st.push(cur);
            cout << cur->key << " ";
            cur = cur->left;
        }

        auto top = st.top();
        st.pop();
        cur = top->right;
    }

}

/// <summary>
/// 非递归的中序
/// </summary>
void test2()
{
    int arr[] = { 6,1,8,3,2,4,9 };
    old::BSTree<int> t;
    for (auto n : arr)
    {
        t.insert(n);
    }
    // t.inOrder();

    std::stack<const old::BSTreeNode<int>*> st;
    auto root = t.GetRoot();

    auto cur = root;

    while (cur || !st.empty())
    {
        while (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }

        auto top = st.top();
        cout << top->key << " ";
        st.pop();
        cur = top->right;
    }

}

/// <summary>
/// 非递归的后续
/// </summary>
void test3()
{
    int arr[] = { 6,1,8,3,2,4,9 };
    old::BSTree<int> t;
    for (auto n : arr)
    {
        t.insert(n);
    }
    // t.inOrder();

    std::stack<const old::BSTreeNode<int>*> st;
    auto root = t.GetRoot();

    const old::BSTreeNode<int>* cur = root;
    const old::BSTreeNode<int>* pre = nullptr;

    while (cur || !st.empty())
    {
        while (cur != nullptr)
        {
            st.push(cur);
            cur = cur->left;
        }

        auto top = st.top();
        assert(top);
        if (top->right == nullptr || top->right == pre)
        {
            cout << top->key << " ";
            st.pop();
            pre = top;
        }
        else
        {
            cur = top->right;
        }
        
    }

}

int main()
{
    //test1();
    //cout << endl;
    //test2();
    test3();

    return 0;
}
