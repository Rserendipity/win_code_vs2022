#pragma once

#include <iostream>
#include <vector>
#include <deque>

namespace cjj {
    using std::cout;
    using std::endl;

    template<class T>
    struct less {
        bool operator()(const T &t1, const T &t2) {
            return t1 < t2;
        }
    };

    template<class T>
    struct greater {
        bool operator()(const T &t1, const T &t2) {
            return t1 > t2;
        }
    };


    template<class T, class Constructor = std::vector<T>, class Compare = less<T>>
    class priority_queue {
    public:
        void push(const T& val) {
            _obj.push_back(val);
            adjust_up(size() - 1);
        }

        void pop() noexcept(false) {
            if (empty())
                throw std::runtime_error("illegal pop");

            std::swap(_obj[0], _obj[size() - 1]);
            _obj.pop_back();
            adjust_down(0);
        }

        T top() noexcept(false) {
            if (empty())
                throw std::runtime_error("illegal top");

            return _obj[0];
        }

        size_t size() const noexcept {
            return _obj.size();
        }

        bool empty() const noexcept {
            return _obj.empty();
        }

    private:

        void adjust_up(int child) {
            //   0
            //  1 2
            // 3 4 5
            int parent = (child - 1) / 2;

            while (child > 0) {
                if (_com(_obj[parent], _obj[child])) {
                    std::swap(_obj[parent], _obj[child]);
                    child = parent;
                    parent = (child - 1) / 2;
                } else {
                    break;
                }
            }
        }

        void adjust_down(int parent) {
            int child = parent * 2 + 1; // left child

            while (child < size()) {
                if (child + 1 < _obj.size() && _com(_obj[child], _obj[child + 1]))
                    ++child;
                if (_com(_obj[parent], _obj[child])) {
                    std::swap(_obj[parent], _obj[child]);
                    parent = child;
                    child = parent * 2 + 1;
                } else {
                    break;
                }
            }
        }

        Constructor _obj;
        Compare _com;
    };

    void testPriorityQueue() {
        priority_queue<int, std::deque<int>, greater<int>> pq;
        pq.push(1);
        pq.push(0);
        pq.push(5);
        pq.push(2);
        pq.push(1);
        pq.push(7);

        while (!pq.empty()) {
            cout << pq.top() << " ";
            pq.pop();
        }
    }

}