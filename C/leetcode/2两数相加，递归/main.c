#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
static struct ListNode* getNewNode(int x) {
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = x;
    p->next = NULL;
    return p;
}

struct ListNode* add(struct ListNode* l1, struct ListNode* l2, int cur) {
    if (l1 == NULL && l2 == NULL) {
        if (cur == 0) {
            return NULL;
        }
        else {
            return getNewNode(cur);
        }
    }
    else if (l1 == NULL && l2 != NULL) {
        int sum = l2->val + cur;
        cur = sum / 10;
        sum %= 10;
        struct ListNode* newNode = getNewNode(sum);
        newNode->next = add(NULL, l2->next, cur);
        return newNode;
    }
    else if (l1 != NULL && l2 == NULL) {
        int sum = l1->val + cur;
        cur = sum / 10;
        sum %= 10;
        struct ListNode* newNode = getNewNode(sum);
        newNode->next = add(l1->next, NULL, cur);
        return newNode;
    }
    else {
        int sum = l1->val + l2->val + cur;
        cur = sum / 10;
        sum %= 10;
        struct ListNode* newNode = getNewNode(sum);
        newNode->next = add(l1->next, l2->next, cur);
        return newNode;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return add(l1, l2, 0);
}

int main() 
{

    return 0;
}
