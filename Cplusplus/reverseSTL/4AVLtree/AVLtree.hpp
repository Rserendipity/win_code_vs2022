#pragma once

#include <iostream>
#include <cassert>

namespace cjj {
    using std::cout;
    using std::endl;


    template<class K, class V>
    struct AVLTreeNode {
        AVLTreeNode<K, V> *_left;
        AVLTreeNode<K, V> *_right;
        AVLTreeNode<K, V> *_parent;
        int _bf;
        std::pair<K, V> _kv;

        explicit AVLTreeNode(const std::pair<K, V> &kv)
                : _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _bf(0) {}
    };

    template<class K, class V>
    class AVLTree {
    private:
        using Node = AVLTreeNode<K, V>;
    public:
        bool insert(const std::pair<K, V> &kv) {
            if (_root == nullptr) {
                _root = new Node(kv);
                return true;
            }

            // 找到合适的插入地点
            Node *parent = nullptr, *cur = _root;
            while (cur) {
                if (kv.first < cur->_kv.first) {
                    parent = cur;
                    cur = cur->_left;
                } else if (kv.first > cur->_kv.first) {
                    parent = cur;
                    cur = cur->_right;
                } else {
                    return false;
                }
            }

            // 插入新的节点
            cur = new Node(kv);
            if (kv.first < parent->_kv.first) {
                parent->_left = cur;
            } else {
                parent->_right = cur;
            }
            cur->_parent = parent;

            // 更新 bf 因子
            while (parent) {
                if (parent->_left == cur) {
                    parent->_bf--;
                } else {
                    parent->_bf++;
                }

                if (parent->_bf == 0) {
                    break;
                } else if (parent->_bf == 1 || parent->_bf == -1) {
                    // 需要继续更新
                    cur = parent;
                    parent = parent->_parent;
                } else if (parent->_bf == 2 || parent->_bf == -2) {
                    // 需要旋转
                    if (parent->_bf == 2 && cur->_bf == 1) {
                        RotateL(parent);
                    } else if (parent->_bf == -2 && cur->_bf == -1) {
                        RotateR(parent);
                    } else {

                    }
                    break;
                } else {
                    assert("this tree was not AVL tree");
                }
            }


            return true;
        }

        void inOrder() const noexcept {
            _inOrder(_root);
        }

        void preOrder() const noexcept {
            _preOrder(_root);
        }

    private:
        void _inOrder(Node *head) const noexcept {
            if (head == nullptr)
                return;
            _inOrder(head->_left);
            cout << head->_kv.first << ":" << head->_kv.second << endl;
            _inOrder(head->_right);
        }

        void _preOrder(Node *head) const noexcept {
            if (head == nullptr)
                return;
            cout << head->_kv.first << ":" << head->_kv.second << endl;
            _preOrder(head->_left);
            _preOrder(head->_right);
        }

        void RotateL(Node *parent) {
            Node *childR = parent->_right;
            Node *childRL = childR->_left;

            parent->_right = childRL;
            childR->_left = parent;

            // 处理新root的 parent 指针
            Node *pParent = parent->_parent;
            if (pParent != nullptr) {
                if (pParent->_left == parent) {
                    pParent->_left = childR;
                } else {
                    pParent->_right = childR;
                }
                childR->_parent = pParent;
            } else {
                _root = childR;
                childR->_parent = nullptr;
            }
            // 处理原parent的父指针
            parent->_parent = childR;
            // 处理LR节点的父指针
            if (childRL != nullptr) {
                childRL->_parent = parent;
            }

            parent->_bf = childR->_bf = 0;
        }

        void RotateR(Node *parent) {
            Node *childL = parent->_left;
            Node *childLR = childL->_right;

            parent->_left = childLR;
            childL->_right = parent;

            Node *pParent = parent->_parent;
            if (pParent != nullptr) {
                if (pParent->_left == parent) {
                    pParent->_left = childL;
                } else {
                    pParent->_right = childL;
                }
                childL->_parent = pParent;
            } else {
                _root = childL;
                childL->_parent = nullptr;
            }

            parent->_parent = childL;
            if (childLR != nullptr) {
                childLR->_parent = parent;
            }
            parent->_bf = childL->_bf = 0;
        }

    private:
        Node *_root = nullptr;
    };


    void test1() {
        AVLTree<int, int> tree;
        cout << tree.insert(std::make_pair(20, 10)) << endl;
        cout << tree.insert(std::make_pair(30, 10)) << endl;
        cout << tree.insert(std::make_pair(10, 10)) << endl;
        cout << tree.insert(std::make_pair(40, 10)) << endl;
        tree.inOrder();
    }


    void test2() {
        AVLTree<int, int> tree;
        cout << tree.insert(std::make_pair(10, 10)) << endl;
        cout << tree.insert(std::make_pair(20, 10)) << endl;
        cout << tree.insert(std::make_pair(30, 10)) << endl;
        cout << tree.insert(std::make_pair(40, 10)) << endl;
        cout << tree.insert(std::make_pair(50, 10)) << endl;
        cout << tree.insert(std::make_pair(60, 10)) << endl;
        cout << tree.insert(std::make_pair(70, 10)) << endl;
        cout << tree.insert(std::make_pair(80, 10)) << endl;
        tree.preOrder();
        cout << endl;
        tree.inOrder();
    }

    void test3() {
        AVLTree<int, int> tree;
        cout << tree.insert(std::make_pair(80, 10)) << endl;
        cout << tree.insert(std::make_pair(70, 10)) << endl;
        cout << tree.insert(std::make_pair(60, 10)) << endl;
        cout << tree.insert(std::make_pair(50, 10)) << endl;
        cout << tree.insert(std::make_pair(40, 10)) << endl;
        cout << tree.insert(std::make_pair(30, 10)) << endl;
        cout << tree.insert(std::make_pair(20, 10)) << endl;
        cout << tree.insert(std::make_pair(10, 10)) << endl;
        tree.preOrder();
        cout << endl;
        tree.inOrder();
    }
}
