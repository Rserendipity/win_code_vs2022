#pragma once
#include <iostream>
#include "list.hpp"

namespace cjj {
    using std::cout;
    using std::endl;

    template<class T>
    class queue {
    public:
        void push(const T& val) {
            _lt.push_back(val);
        }
        void pop() noexcept(false) {
            if (_lt.empty())
                throw std::runtime_error("illegal pop");
            _lt.pop_front();
        }
        T top() noexcept(false) {
            if (_lt.empty())
                throw std::runtime_error("illegal top");
            auto it = _lt.begin();
            return *it;
        }

        bool empty() const noexcept {
            return _lt.empty();
        }

        size_t size() const noexcept {
            return _lt.size();
        }

    private:
        list<T> _lt;
    };

    void testQueue() {
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);

        while (!q.empty()) {
            cout << q.top() << " ";
            q.pop();
        }

    }
}