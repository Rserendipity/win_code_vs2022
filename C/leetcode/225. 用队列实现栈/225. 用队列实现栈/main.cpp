#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
	MyStack() {

	}

	void push(int x) {
		q1.push(x);
	}

	int pop() {
		int sz = q1.size();
		while (--sz) {
			q2.push(q1.front());
			q1.pop();
		}
		int ret = q1.front();
		q1 = q2;
		q2 = queue<int>();
		return ret;
	}

	int top() {
		int ret = 0;
		int sz = q1.size();
		while (--sz) {
			q2.push(q1.front());
			q1.pop();
		}
		ret = q1.front();
		q2.push(ret);
		q1 = q2;
		q2 = queue<int>();
		return ret;
	}

	bool empty() {
		return q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack* obj = new MyStack();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->top();
* bool param_4 = obj->empty();
*/
int main()
{

    system("pause");
    return 0;
}
