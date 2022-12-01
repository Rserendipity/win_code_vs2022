#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (!minSt.empty()) {
            if (val <= minSt.top()) {
                minSt.push(val);
            }
        }
        else {
            minSt.push(val);
        }
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (top <= minSt.top()) {
            minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};


int main()
{
    MinStack* minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    minStack->getMin();
	minStack->pop();
    minStack->top();
	minStack->getMin();

    return 0;
}
