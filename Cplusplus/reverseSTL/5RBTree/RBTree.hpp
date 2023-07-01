#pragma once

#include <iostream>
#include <cassert>

namespace cjj {
    using std::cout;
    using std::endl;

    enum Color {
        BLACK,
        RED
    };

    template<class K, class V>
    struct RBTreeNode {
        RBTreeNode<K, V> *_left;
        RBTreeNode<K, V> *_right;
        RBTreeNode<K, V> *_parent;

        std::pair<K, V> _kv;
        Color _color;

        explicit RBTreeNode(const std::pair<K, V> &kv)
                : _kv(kv), _left(nullptr), _right(nullptr), _parent(nullptr), _color(RED) {}
    };

    template<class K, class V>
    class RBTree {
    private:
        using Node = RBTreeNode<K, V>;
    public:
        RBTree() = default;

        bool insert(const std::pair<K, V> &kv) {
            if (_root == nullptr) {
                _root = new Node(kv);
                _root->_color = BLACK;
                return true;
            }

            Node *parent = nullptr;
            Node *cur = _root;
            while (cur) {
                if (cur->_kv.first < kv.first) {
                    parent = cur;
                    cur = cur->_right;
                } else if (cur->_kv.first > kv.first) {
                    parent = cur;
                    cur = cur->_left;
                } else {
                    return false;
                }
            }

            cur = new Node(kv);
            if (parent->_kv.first > kv.first) {
                parent->_left = cur;
            } else {
                parent->_right = cur;
            }
            cur->_parent = parent;

            while (parent && parent->_color == RED) {
                Node *grandfather = parent->_parent;
                if (grandfather->_left == parent) {
                    Node *uncle = grandfather->_right;
                    // 情况1：u存在且为红，变色处理，并继续往上处理
                    if (uncle && uncle->_color == RED) {
                        parent->_color = BLACK;
                        uncle->_color = BLACK;
                        grandfather->_color = RED;

                        // 继续往上调整
                        cur = grandfather;
                        parent = cur->_parent;
                    } else // 情况2+3：u不存在/u存在且为黑，旋转+变色
                    {
                        //     g
                        //   p   u
                        // c
                        if (cur == parent->_left) {
                            RotateR(grandfather);
                            parent->_color = BLACK;
                            grandfather->_color = RED;
                        } else {
                            //     g
                            //   p   u
                            //     c
                            RotateL(parent);
                            RotateR(grandfather);
                            cur->_color = BLACK;
                            //parent->_col = RED;
                            grandfather->_color = RED;
                        }

                        break;
                    }
                } else // (grandfather->_right == parent)
                {
                    //    g
                    //  u   p
                    //        c
                    Node *uncle = grandfather->_left;
                    // 情况1：u存在且为红，变色处理，并继续往上处理
                    if (uncle && uncle->_color == RED) {
                        parent->_color = BLACK;
                        uncle->_color = BLACK;
                        grandfather->_color = RED;

                        // 继续往上调整
                        cur = grandfather;
                        parent = cur->_parent;
                    } else // 情况2+3：u不存在 / u存在且为黑，旋转+变色
                    {
                        //    g
                        //  u   p
                        //        c
                        if (cur == parent->_right) {
                            RotateL(grandfather);
                            grandfather->_color = RED;
                            parent->_color = BLACK;
                        } else {
                            //    g
                            //  u   p
                            //    c
                            RotateR(parent);
                            RotateL(grandfather);
                            cur->_color = BLACK;
                            grandfather->_color = RED;
                        }

                        break;
                    }
                }
            }
            _root->_color = BLACK;
            return true;
        }

        void inOrder() const noexcept {
            _inOrder(_root);
            cout << endl;
        }

        void preOrder() const noexcept {
            _preOrder(_root);
            cout << endl;
        }

    private:
        int high(Node *root) {
            if (root == nullptr) {
                return 0;
            } else {
                return std::max(high(root->_left), high(root->_right)) + 1;
            }
        }

        void _inOrder(Node *head) const noexcept {
            if (head == nullptr)
                return;
            _inOrder(head->_left);
            cout << head->_kv.first << " ";
            _inOrder(head->_right);
        }

        void _preOrder(Node *head) const noexcept {
            if (head == nullptr)
                return;
            cout << head->_kv.first << " ";
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
        }

    private:
        Node *_root = nullptr;
    };


    void test1() {
        RBTree<int, int> tree;
        tree.insert(std::make_pair(10, 0));
        tree.insert(std::make_pair(20, 0));
        tree.insert(std::make_pair(30, 0));
        tree.insert(std::make_pair(40, 0));
        tree.insert(std::make_pair(50, 0));
        tree.insert(std::make_pair(60, 0));
        tree.insert(std::make_pair(70, 0));

        tree.preOrder();
        tree.inOrder();
    }

}