#pragma once

#include <iostream>
#include <exception>
#include <cassert>

namespace MyVector {

    template<class T, class Ref, class Ptr>
    struct _iterator {
        using self = _iterator<T, Ref, Ptr>;

        _iterator(T* ptr) {
            this->ptr = ptr;
        }

        Ref operator*() {
            return *ptr;
        }

        Ptr operator->() {
            return ptr;
        }

        self operator++() {
            ++ptr;
            return *this;
        }

        self operator++(int) {
            self t(ptr);
            ++ptr;
            return t;
        }

        bool operator==(const self& other) {
            return ptr == other.ptr;
        }

        bool operator!=(const self& other) {
            return ptr != other.ptr;
        }

        T* ptr;
    };


    template<class T>
    class vector {
        using iterator = _iterator<T, T&, T*>;
        using const_iterator = _iterator<T, const T&, const T*>;

    public:
        explicit vector(int capacity = 5) {
            _arr = new T[capacity];
            _size = 0;
            _capacity = capacity;
        }

        template<class InputIterator>
        vector(InputIterator begin, InputIterator end) {
            vector<T> v;
            while (begin != end) {
                v.push_back(*begin);
                ++begin;
            }
            swap(v);
        }

        vector(size_t size, const T& value) {
            vector<T> v;
            for (size_t i = 0; i < size; i++) {
                v.push_back(value);
            }
            swap(v);
        }

        vector(const vector<T>& other) {
            // 复用
            vector<T> v(other.begin(), other.end());
            swap(v);
        }

        void swap(vector<T>& other) {
            std::swap(_arr, other._arr);
            std::swap(_size, other._size);
            std::swap(_capacity, other._capacity);
        }

        iterator begin() {
            return iterator(_arr);
        }

        iterator end() {
            return iterator(_arr + _size);
        }

        const_iterator begin() const {
            return const_iterator(_arr);
        }

        const_iterator end() const {
            return const_iterator(_arr + _size);
        }

        int size() const {
            return _size;
        }

        void reverse(int newCapacity) {
            if (newCapacity <= _capacity) {
                // nothing to do
            } else {
                T* tmp = new T[newCapacity];
                for (int i = 0; i < _size; i++) {
                    tmp[i] = _arr[i];
                }
                _arr = tmp;
                _capacity = newCapacity;
            }
        }

        void resize(int newSize, const T& value = T()) {
            if (newSize < _size) {
                // nothing to do
            } else if (newSize < _capacity) {
                for (int i = _size; i < newSize; i++) {
                    _arr[i] = value;
                }
            } else {
                reverse(newSize);
                for (int i = _size; i < newSize; i++) {
                    _arr[i] = value;
                }
            }
        }

        void push_back(const T& value) {
            checkCapacity();
            _arr[_size++] = value;
        }

        T& operator[](int index) {
            checkIndex(index);
            return _arr[index];
        }

    private:
        void checkCapacity() {
            if (_capacity == 0) {
                reverse(5);
            } else if (_size >= _capacity) {
                reverse(2 * _capacity);
            }
        }

        void checkIndex(int index) {
            if (index < 0 || index >= _size) {
                assert(0);
                // or throw an exception
            }
        }

    private:
        T* _arr;
        int _size;
        int _capacity;
    };

    void test01() {
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        v.push_back(6);


        for (int i : v) {
            std::cout << i << " ";
        }

        std::cout << std::endl;

        for (auto n : v) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        vector<int> other(v);
        other[0] = 99;
        other[1] = 88;
        other[2] = 77;

        for (auto n : other) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

    }
}