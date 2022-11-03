#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
	MyQueue() {}

	void push(int x) {
		s1.push(x);
	}

	int pop() {
		int sz = s1.size();
		while (--sz) {
			s2.push(s1.top());
			s1.pop();
		}
		int ret = s1.top();
		s1.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return ret;
	}

	int peek() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		int ret = s2.top();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return ret;
	}

	bool empty() {
		return s1.empty();
	}
private:
	stack<int> s1;
	stack<int> s2;
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue* obj = new MyQueue();
* obj->push(x);
* int param_2 = obj->pop();
* int param_3 = obj->peek();
* bool param_4 = obj->empty();
*/
int main()
{

    system("pause");
    return 0;
}
