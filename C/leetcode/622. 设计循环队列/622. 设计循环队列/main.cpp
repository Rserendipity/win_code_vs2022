#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class MyCircularQueue {
public:
	MyCircularQueue(int k) {
		array = new int[k] {0};
		head = 0;
		tail = 0;
		count = 0;
		capicity = k;
	}

	bool enQueue(int value) {
		if (!isFull()) {
			tail %= capicity;
			array[tail++] = value;
			count++;
			return true;
		}
		else {
			return false;
		}
	}

	bool deQueue() {
		if (!isEmpty()) {
			head++;
			head %= capicity;
			count--;
			return true;
		}
		else {
			return false;
		}
	}

	int Front() {
		if (!isEmpty()) {
			return array[head];
		}
		else {
			return -1;
		}
	}

	int Rear() {
		if (!isEmpty()) {
			return array[tail - 1];
		}
		else {
			return -1;
		}
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count == capicity;
	}
	~MyCircularQueue() {
		delete[] array;
		head = 0;
		tail = 0;
	}
private:
	int* array;
	int head;
	int tail;
	int count;
	int capicity;
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

int main()
{
	MyCircularQueue q(3);
	MyCircularQueue circularQueue(3); // 设置长度为 3


	cout << circularQueue.enQueue(1) << endl;
	cout << circularQueue.enQueue(2) << endl;
	cout << circularQueue.enQueue(3) << endl;
	cout << circularQueue.enQueue(4) << endl;

	cout << circularQueue.Rear() << endl;
	cout << circularQueue.isFull() << endl;
	cout << circularQueue.deQueue() << endl;

	cout << circularQueue.enQueue(4) << endl;
	cout << circularQueue.Rear() << endl;
	cout << circularQueue.Front() << endl;



	system("pause");
	return 0;
}
