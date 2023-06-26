#pragma once

#include <iostream>

namespace cjj {
    using std::cout;
    using std::endl;
    using std::string;


    template<class T>
    class vector {
    private:
        const int DEFAULT_CAPACITY = 4;

    public:
        typedef T *iterator;
        typedef const T *const_iterator;

        iterator begin() noexcept {
            return _start;
        }

        iterator end() noexcept {
            return _end;
        }

        const_iterator begin() const noexcept {
            return _start;
        }

        const_iterator end() const noexcept {
            return _end;
        }

        vector()
                : _start(nullptr), _end(nullptr), _capacity(nullptr) {
            _start = new T[DEFAULT_CAPACITY]{};
            _end = _start;
            _capacity = _start + DEFAULT_CAPACITY;
        }


        template<class InputIterator>
        vector(InputIterator begin, InputIterator end)
                : _start(nullptr), _end(nullptr), _capacity(nullptr) {
            while (begin != end) {
                push_back(*begin);
                ++begin;
            }
        }

        vector(const vector<T> &v)
                : _start(nullptr), _end(nullptr), _capacity(nullptr) {
            vector<T> temp(v.begin(), v.end());
            swap(temp);
        }

        vector(size_t n, const T &val)
                : _start(nullptr), _end(nullptr), _capacity(nullptr) {
            reserve(n);
            for (size_t i = 0; i < n; i++) {
                push_back(val);
            }
        }

        vector(int n, const T &val)
                : _start(nullptr), _end(nullptr), _capacity(nullptr) {
            reserve(n);
            for (size_t i = 0; i < n; i++) {
                push_back(val);
            }
        }

        ~vector() {
            delete[] _start;
            _start = _end = _capacity = nullptr;
        }

        void swap(vector<T> &v) {
            std::swap(_start, v._start);
            std::swap(_end, v._end);
            std::swap(_capacity, v._capacity);
        }

        void reserve(int n) {
            // 不会缩容
            if (n < capacity()) {
                return;
            }

            // n > capacity 需要扩容了
            T *newSpace = new T[n]{};
            size_t oldSize = size();
            for (size_t i = 0; i < oldSize; i++) {
                newSpace[i] = _start[i];
            }
            delete[] _start;
            _start = newSpace;
            _end = _start + oldSize;
            _capacity = _start + n;
        }

        size_t size() const noexcept {
            return _end - _start;
        }

        size_t capacity() const noexcept {
            return _capacity - _start;
        }

        void push_back(const T &val) {
//            int n = size();
//            if (n >= capacity()) {
//                reserve(2 * n);
//            }
//            _start[n] = val;
//            _end++;
            insert(size(), val);
        }

        T &operator[](size_t pos) noexcept(false) {
            if (pos >= size())
                throw std::out_of_range("out of range");
            return _start[pos];
        }

        const T &operator[](size_t pos) const noexcept(false) {
            if (pos >= size())
                throw std::out_of_range("out of range");
            return _start[pos];
        }

        vector<T> &operator=(vector<T> v) {
            swap(v);
            return *this;
        }

        vector<T> &operator*() {
            return *this;
        }

        void insert(size_t pos, const T &val) noexcept(false) {
            if (pos > size())
                throw std::out_of_range("out of range");
            reserve(size() + 1);
            int end = size() + 1;
            while (end > pos) {
                _start[end] = _start[end - 1];
                end--;
            }

            _start[pos] = val;
            _end++;
        }

        void erase(size_t pos) noexcept(false) {
            size_t n = size();
            if (pos >= n)
                throw std::out_of_range("out of range");
            while (pos < n) {
                _start[pos] = _start[pos + 1];
                pos++;
            }
            _end--;
        }

    private:
        T *_start;
        T *_end;
        T *_capacity;
    };

    void test1() {
        vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        cout << v[0] << endl;
        cout << v[1] << endl;
        cout << v[2] << endl;

        for (auto n: v) {
            cout << n << endl;
        }


        vector<int>::iterator it = v.begin();
        while (it != v.end()) {
            cout << *it << endl;
        }
    }

    void test2() {
        vector<int> v1;

        v1.push_back(10);
        v1.push_back(99);
        v1.push_back(1111);


        vector<int> v2(v1);
        v2.insert(v2.size(), 888);
        v2.insert(0, 1234);

        for (int n: v2) {
            cout << n << " ";
        }
        cout << endl;
        v2.erase(1);

        for (int n: v2) {
            cout << n << " ";
        }
    }

    void test3() {
        vector<vector<int>> vv;

        vv.push_back(vector<int>(3,1));
        vv.push_back(vector<int>(4,7));
        vv.push_back(vector<int>(5,9));

        for (auto &v: vv) {
            for (auto &n: v) {
                cout << n << " ";
            }
            cout << endl;
        }

    }
}