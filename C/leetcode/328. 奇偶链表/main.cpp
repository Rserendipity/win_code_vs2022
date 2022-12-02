#include <bits/stdc++.h>
using namespace std;
/**
  Definition for singly-linked list.*/
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
    ListNode *oddEvenList(ListNode *head)
    {
        int i = 0;
        ListNode *oddHead = nullptr;
        ListNode *oddMove = nullptr;
        ListNode *evenHead = nullptr;
        ListNode *evenMove = nullptr;
        ListNode *cur = head;
        while (cur)
        {
            if (i % 2 == 0)
            {
                if (oddHead == nullptr)
                {
                    oddHead = oddMove = cur;
                }
                else
                {
                    oddMove->next = cur;
                    oddMove = cur;
                }
            }
            else
            {
                if (evenHead == nullptr)
                {
                    evenHead = evenMove = cur;
                }
                else
                {
                    evenMove->next = cur;
                    evenMove = cur;
                }
            }
            cur = cur->next;
            i++;
        }
        if (oddHead)
        {
            oddMove->next = evenHead;
            if (evenHead)
            {
                evenMove->next = nullptr;
            }
        }
        else
        {
            oddHead = evenHead;
        }
        return oddHead;
    }
};