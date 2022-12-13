#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class MyLinkedList {
    struct ListNode {
        ListNode* prev;
        ListNode* next;
        int val;
        ListNode(const int& val) : prev(nullptr), next(nullptr), val(val) {}
    };
public:
    MyLinkedList()
        : _head(new ListNode(-1))
        , _size(0)
    {
        _head->prev = _head;
        _head->next = _head;
    }

    int get(int index) {
        ListNode* cur = _head->next;
        while (cur != _head && index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _head->next;
        _head->next->prev = newNode;
        newNode->prev = _head;
        _head->next = newNode;
        _size++;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* prev = _head->prev;
        newNode->prev = prev;
        newNode->next = _head;
        prev->next = newNode;
        _head->prev = newNode;
        _size++;
    }

    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
            return;
        }

        if (index > _size) {
            return;
        }

        ListNode* cur = _head->next;
        while (index--) {
            cur = cur->next;
        }

        ListNode* prev = cur->prev;
        ListNode* newNode = new ListNode(val);
        newNode->prev = prev;
        newNode->next = cur;
        prev->next = newNode;
        cur->prev = newNode;
    }

    void deleteAtIndex(int index) {
        if (index >= _size) {
            return;
        }

        ListNode* cur = _head->next;
        while (index--) {
            cur = cur->next;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
        _size--;
    }

private:
    ListNode* _head;
    int _size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main()
{
    MyLinkedList list;
	list.addAtHead(2);
	list.deleteAtIndex(1);
	list.addAtHead(2);
	list.addAtHead(7);
	list.addAtHead(3);
	list.addAtHead(2);
	list.addAtHead(5);
	list.addAtTail(5);
	cout << list.get(5);
	list.deleteAtIndex(6);
	list.deleteAtIndex(4);
        
    return 0;
}
