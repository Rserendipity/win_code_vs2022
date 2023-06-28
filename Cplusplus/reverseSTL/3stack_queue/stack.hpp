#pragma once

#include <iostream>
#include "list.hpp"

namespace cjj {
    using std::cout;
    using std::endl;

    template<class T>
    class stack {
    public:
        stack() noexcept = default;

        stack(const stack<T> &st) noexcept {
            _lt(st._lt);
        }

        stack(stack<T> &&st) noexcept {
            _lt.swap(st._lt);
        }

        stack<T> &operator=(const stack<T> &st) noexcept {
            if (this != &st) {
                _lt(st._lt);
            }
            return *this;
        }
        ~stack() noexcept = default;


        void push(const T &val) {
            _lt.push_back(val);
        }

        void pop() noexcept(false) {
            if (_lt.empty())
                throw std::runtime_error("Illegal pop");
            _lt.pop_back();
        }

        T top() noexcept(false) {
            if (_lt.empty())
                throw std::runtime_error("Illegal top");
            auto it = _lt.end();
            --it;
            return *it;
        }

        size_t size() const noexcept {
            return _lt.size();
        }

        bool empty() const noexcept {
            return _lt.empty();
        }

    private:
        list<T> _lt;
    };

    void testStack() {
        stack<int> st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }
}