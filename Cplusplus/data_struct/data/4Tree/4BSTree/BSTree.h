#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<class K>
struct BSTreeNode {
	BSTreeNode<K>* left;
	BSTreeNode<K>* right;
	K val;
	BSTreeNode(const K& val) :val(val), left(nullptr), right(nullptr) {}
};

template<class K>
class BSTree {
	typedef BSTreeNode<K> Node;

public:
	BSTree()
		:_root(nullptr)
	{}

	bool insert(const K& val)
	{
		if (_root == nullptr) 
		{
			_root = new Node(val);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->val < val)
			{
				parent = cur;
				cur = cur->right;
			}
			else if (cur->val > val)
			{
				parent = cur;
				cur = cur->left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(val);
		if (parent->val < val)
		{
			parent->right = cur;
		}
		else
		{
			parent->left = cur;
		}
		return true;
	}

	bool find(const K& val) const
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->val < val)
			{
				cur = cur->right;
			}
			else if (cur->val > val)
			{
				cur = cur->left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	void inOrder() const
	{
		_inOrder(_root);
		cout << endl;
	}

private:
	void _inOrder(const Node* root) const 
	{
		if (root != nullptr)
		{
			_inOrder(root->left);
			cout << root->val << " ";
			_inOrder(root->right);
		}
	}
	Node* _root;
};
