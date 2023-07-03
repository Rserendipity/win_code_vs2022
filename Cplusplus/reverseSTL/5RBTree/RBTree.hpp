#pragma once

#include <iostream>
#include <cassert>
#include <random>

namespace cjj_stl {
    using std::cout;
    using std::endl;

    enum Color {
        BLACK,
        RED
    };

    template<class T>
    struct RBTreeNode {
        RBTreeNode<T> *_left;
        RBTreeNode<T> *_right;
        RBTreeNode<T> *_parent;

        T _val;
        Color _color;

        explicit RBTreeNode(const T &val)
                : _val(val), _left(nullptr), _right(nullptr), _parent(nullptr), _color(RED) {}
    };

    template<class T, class Ref, class Ptr>
    class RBTreeIterator {
    private:
        using Node = RBTreeNode<T>;
        using self = RBTreeIterator<T, Ref, Ptr>;
    public:
        explicit RBTreeIterator(Node *node)
                : _node(node) {}

        Ref operator*() {
            return _node->_val;
        }

        Ptr operator->() {
            return &_node->val;
        }

        bool operator!=(const self &it) {
            return it._node != _node;
        }

        self &operator++() {
            if (_node->_right) {
                // 1、右不为空，下一个就是右子树的最左节点
                Node *subLeft = _node->_right;
                while (subLeft->_left) {
                    subLeft = subLeft->_left;
                }

                _node = subLeft;
            } else {
                // 2、右为空，沿着到根的路径，找孩子是父亲左的那个祖先
                Node *cur = _node;
                Node *parent = cur->_parent;
                while (parent && cur == parent->_right) {
                    cur = parent;
                    parent = parent->_parent;
                }

                _node = parent;
            }

            return *this;
        }

        self &operator--() {
            if (_node->_left) {
                // 1、左不为空，找左子树最右节点
                Node *subRight = _node->_left;
                while (subRight->_right) {
                    subRight = subRight->_right;
                }

                _node = subRight;
            } else {
                // 2、左为空，孩子是父亲的右的那个祖先
                Node *cur = _node;
                Node *parent = cur->_parent;
                while (parent && cur == parent->_left) {
                    cur = parent;
                    parent = parent->_parent;
                }

                _node = parent;
            }

            return *this;
        }

    private:
        Node *_node;
    };


    template<class K, class V, class KeyOfT>
    class RBTree {
    private:
        using Node = RBTreeNode<V>;
    public:
        using iterator = RBTreeIterator<V, V &, V *>;

        iterator begin() {
            Node *cur = _root;
            while (cur && cur->_left) {
				cur = cur->_left;
            }
            return iterator(cur);
        }

        iterator end() {
            return iterator(nullptr);
        }

        RBTree() = default;

        bool insert(const V &val) {
            if (_root == nullptr) {
                _root = new Node(val);
                _root->_color = BLACK;
                return true;
            }

            KeyOfT kof;
            Node *parent = nullptr;
            Node *cur = _root;
            while (cur) {
                if (kof(cur->_val) < kof(val)) {
                    parent = cur;
                    cur = cur->_right;
                } else if (kof(cur->_val) > kof(val)) {
                    parent = cur;
                    cur = cur->_left;
                } else {
                    return false;
                }
			}

            cur = new Node(val);
            if (kof(parent->_val) > kof(val)) {
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

    private:
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


}