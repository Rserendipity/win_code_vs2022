#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

struct Node {
	int val;
	struct Node* next;
	Node(int val) :val(val), next(nullptr) {}
	Node(int val, struct Node* p) :val(val), next(p) {}
};

class MyCircularQueue {
public:
	MyCircularQueue(int k) {
		head = tail = new Node(0);
		struct Node* cur = head;
		while (k--) {
			cur->next = new Node(0);
			cur = cur->next;
		}
		cur->next = head;
	}

	bool enQueue(int value) {
		if (!isFull()) {
			tail->val = value;
			tail = tail->next;
			return true;
		}
		else {
			return false;
		}
	}

	bool deQueue() {
		if (!isEmpty()) {
			head = head->next;
			return true;
		}
		else {
			return false;
		}
	}

	int Front() {
		if (!isEmpty()) {
			return head->val;
		}
		else {
			return -1;
		}
	}

	int Rear() {
		if (!isEmpty()) {
			Node* cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			return cur->val;
		}
		else {
			return -1;
		}
	}

	bool isEmpty() {
		return head == tail;
	}

	bool isFull() {
		return tail->next == head;
	}

private:
	struct Node* head;
	struct Node* tail;
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/
int main()
{
	MyCircularQueue circularQueue(3); // 设置长度为 3
	cout << circularQueue.enQueue(1);
	cout << circularQueue.enQueue(2);
	cout << circularQueue.enQueue(3);
	cout << circularQueue.enQueue(4);
	cout << circularQueue.Rear();
	cout << circularQueue.isFull();
	cout << circularQueue.deQueue();
	cout << circularQueue.enQueue(4);
	cout << circularQueue.Rear();

    system("pause");
    return 0;
}
