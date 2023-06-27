#include <iostream>
#include <list>

namespace cjj {
    using std::cout;
    using std::endl;


    template<class T>
    struct node {
        T _val;
        node<T> *_prev;
        node<T> *_next;

        explicit node(const T &val) : _val(val), _prev(nullptr), _next(nullptr) {}
    };

    template<class T, class Ref, class Ptr>
    class _list_iterator {
         using Node = node<T>;
         using self = _list_iterator<T, Ref, Ptr>;
    public:
        explicit _list_iterator(Node *p) : head(p) {}

        _list_iterator(const self &it) = default;

        self &operator=(const self &it) {
            if (this != &it) {
                head = it.head;
            }
            return *this;
        }

        ~_list_iterator() = default;

        Ref operator*() {
            return head->_val;
        }

        Ptr operator->() {
            return &operator*();
        }

        self operator++() {
            head = head->_next;
            return self(head);
        }

        self operator++(int) {
            Node *cur = head;
            head = head->_next;
            return self(cur);
        }

        self operator--() {
            head = head->_prev;
            return self(head);
        }

        self operator--(int) {
            Node *cur = head;
            head = head->_prev;
            return self(cur);
        }

        bool operator!=(const self &it) const {
            return head != it.head;
        }

        bool operator==(const self &it) const {
            return head == it.head;
        }

        Node *head;
    };


    template<class T>
    class list {
        using Node = node<T>;
    public:
         using iterator = _list_iterator<T, T &, T *>;
         using const_iterator = _list_iterator<T, const T &, const T *>;

        iterator begin() noexcept {
            return iterator(_head->_next);
        }

        iterator end() noexcept {
            return iterator(_head);
        }

        const_iterator begin() const noexcept {
            return const_iterator(_head->_next);
        }

        const_iterator end() const noexcept {
            return const_iterator(_head);
        }

        list() : _head(nullptr) {
            _head = new Node(-1);
            _head->_next = _head;
            _head->_prev = _head;
        }

        list(const list &lt) : _head(nullptr) {
            list<T> tmp(lt.begin(), lt.end());
            swap(tmp);
        }

        template<class InputIterator>
        list(InputIterator begin, InputIterator end)  : _head(nullptr) {
            list<T> tmp;
            while (begin != end) {
                tmp.push_back(*begin);
            }
            swap(tmp);
        }

        ~list() {
            if (_head == nullptr)
                return;
            Node *cur = _head->_next;
            while (cur != _head) {
                Node *save = cur->_next;
                delete cur;
                cur = save;
            }
            delete _head;
            _head = nullptr;
        }

        void swap(list &lt) noexcept {
            std::swap(_head, lt._head);
        }

        void push_back(const T &val) noexcept {
            insert(end(), val);
        }
        void push_front(const T& val) noexcept {
            insert(begin(), val);
        }

        void pop_front() noexcept {
            erase(begin());
        }
        void pop_back() noexcept {
            erase(--end());
        }

        iterator insert(iterator it, const T &val) noexcept {
            /*
             * head -> 1 -> 2
             *
             * */
            Node *newNode = new Node(val);
            newNode->_next = it.head;
            newNode->_prev = it.head->_prev;
            it.head->_prev->_next = newNode;
            _head->_prev = newNode;
            return it;
        }

        iterator erase(iterator it) noexcept(false) {
//            if (it.head == _head) {
//                throw std::runtime_error("Invalid position!");
//            }
            Node* node = it.head;
            Node* next = node->_next;
            Node* prev = node->_prev;
            prev->_next = next;
            next->_prev = prev;
            return iterator(next);
        }

    private:
        Node *_head;
    };

    void test1() {
        list<int> lt;
        lt.push_back(10);
        lt.push_back(20);
        lt.push_back(30);

        // const list<int> clt(lt);

        for (auto n: lt) {
            cout << n << " ";
        }
        cout << endl;

        lt.insert(lt.begin(), 99);

        for (auto n: lt) {
            cout << n << " ";
        }
        cout << endl;

        auto it = lt.begin();
        ++it;
        lt.erase(it);

        for (auto n: lt) {
            cout << n << " ";
        }
        cout << endl;
    }

    void test2() {
        list<int> lt;
        lt.insert(lt.end(), 10);
        lt.insert(lt.end(), 20);
        lt.insert(lt.end(), 30);

        lt.erase(--lt.end());

        lt.push_back(99);
        lt.push_back(99);

        lt.push_front(123);

        for (auto& n : lt) {
            cout << n << " ";
        }
        cout << endl;
    }
}