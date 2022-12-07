#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);

        if (fast == slow)
        {
            return root;
        }

        if (prev)
        {
            prev->next = nullptr;
        }

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
int main()
{

    return 0;
}
