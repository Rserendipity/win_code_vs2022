#pragma once
#include <iostream>

namespace Cjj {

    template<class T>
    struct ListNode {
        T val;
        ListNode<T> *prev;
        ListNode<T> *next;

        ListNode(const T &value = T()) : val(value), prev(nullptr), next(nullptr) {}
    };

    template<class T, class Ref, class Ptr>
    struct _iterator {
        using self = _iterator<T, Ref, Ptr>;

        _iterator(ListNode<T> *p) {
            this->p = p;
        }

        Ref operator*() {
            return p->val;
        }

        Ptr operator->() {
            return &operator*();
        }

        self operator++() {
            p = p->next;
            return *this;
        }

        bool operator==(const self &other) {
            return p == other.p;
        }

        bool operator!=(const self &other) {
            return p != other.p;
        }

        ListNode<T> *p;
    };

    template<class T>
    class list {
    private:
        using Node = ListNode<T>;

    public:
        using iterator = _iterator<T, T&, T*>;

        list() {
            head = new Node();
            head->next = head;
            head->prev = head;
        }

        ~list() {
            Node *cur = head->next;
            while (cur != head) {
                auto save = cur->next;
                delete cur;
                cur = save;
            }
            delete head;
        }

        iterator begin() {
            return iterator(head->next);
        }

        iterator end() {
            return iterator(head);
        }

        void push_back(const T &value) {
//            auto node = new Node(value);
//            node->next = head;
//            node->prev = head->prev;
//            head->prev->next = node;
//            head->prev = node;
            insert(end(), value);
        }

        void push_front(const T &value) {
            insert(begin(), value);
        }

        void insert(iterator pos, const T & value) {
            auto node = new Node(value);
            auto p = pos.p;
            node->next = p;
            node->prev = p->prev;
            p->prev->next = node;
            p->prev = node;
        }

    private:
        Node *head;
    };

    void test01() {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        for (auto n : lt) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        lt.push_front(99);
        lt.push_front(88);

        list<int>::iterator it = lt.begin();
        while (it != lt.end()) {
            std::cout << *it << " ";
            ++it;
        }
        std::cout << std::endl;

    }
}