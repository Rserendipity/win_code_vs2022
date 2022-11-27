#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template<class K, class V>
struct AVLTreeNode {
	AVLTreeNode<K, V>* left;
	AVLTreeNode<K, V>* right;
	AVLTreeNode<K, V>* parent;
	int bf;
	pair<K, V> kv;
	AVLTreeNode(const pair<K, V>& kv) 
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, bf(0)
		, kv(kv) 
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		// 找到插入的地方
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (kv.first < cur->kv.first)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (kv.first > cur->kv.first)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}

		// 判断插入到左还是右
		cur = new Node(kv);
		if (parent->kv.first < kv.first)
		{
			parent->right = cur;
			cur->parent = parent;
		}
		else
		{
			parent->left = cur;
			cur->parent = parent;
		}

		// 更新平衡因子 --- 右树的高度减去左树的高度
		while (parent != nullptr)
		{
			// 插入到左树 --，右树++
			if (cur == parent->left)
				parent->bf--;
			else
				parent->bf++;

			if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == 1 || parent->bf == -1)
			{
				cur = parent;
				parent = parent->parent;
			}
			else if (parent->bf == 2 || parent->bf == -2)
			{
				// 四种旋转
				if (parent->bf == -2 && cur->bf == -1)
				{
					RotateR(parent); // 右单选

				}
				else if (parent->bf == 2 && cur->bf == 1) // 左单旋
				{
					RotateL(parent); // 左单选
				}
				else if (parent->bf == -2 && cur->bf == 1) // 左右双旋
				{
					RotateLR(parent);
				}
				else if (parent->bf == 2 && cur->bf == -1) // 左右双旋
				{
					RotateRL(parent);
				}
				else
				{
					cout << "Tree Error!" << endl;
					assert(0);
				}

				break;
			}
			else
			{
				// 正常情况下不可能有因子超过2的绝对值，超过了，就说明这棵树原本就有问题
				cout << "Tree Error!" << endl;
				assert(0);
			}
		}

		return true;
	}
	
	void InOrder()
	{
		_InOrder(_root);
	}

	void PreOrder()
	{
		_PreOrder(_root);
	}

private:
	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->kv.first << ": " << root->kv.second << endl;
			_InOrder(root->right);
		}
	}

	void _PreOrder(Node* root)
	{
		if (root)
		{
			cout << root->kv.first << ": " << root->kv.second << endl;
			_PreOrder(root->left);
			_PreOrder(root->right);
		}
	}

	void RotateR(Node* parent)
	{
		Node* parentParent = parent->parent;
		Node* L = parent->left;
		Node* LR = L->right;

		// 确定爷爷和旋转后跟的关系
		if (parentParent)
		{
			// 爷爷非空，则判断父的位置
			if (parentParent->left == parent)
				parentParent->left = L;
			else
				parentParent->right = L;
		}
		else
		{
			// 爷爷为空，说明父就是当前的根节点，
			_root = L;
		}

		// 处理父，父的左应该连接LR，父的父应该更改为L
		parent->left = LR;
		parent->parent = L;

		// 处理LR，LR不为空，则将他的父指向父
		if (LR != nullptr)
			LR->parent = parent;

		// 处理L，L的父应该是爷爷，L的右应该是父
		L->parent = parentParent;
		L->right = parent;

		// 更改平衡因子
		L->bf = parent->bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* parentParent = parent->parent;
		Node* R = parent->right;
		Node* RL = R->left;

		if (parentParent != nullptr)
		{
			if (parentParent->left == parent)
				parentParent->left = R;
			else
				parentParent->right = R;
		}
		else
		{
			_root = R;
		}

		parent->right = RL;
		parent->parent = R;

		if (RL != nullptr)
			RL->parent = parent;

		R->parent = parentParent;
		R->left = parent;

		R->bf = parent->bf = 0;
	}

	void RotateLR(Node* parent)
	{
		RotateL(parent->left);
		RotateR(parent);
	}

	void RotateRL(Node* parent)
	{
		RotateR(parent->right);
		RotateL(parent);
	}

	Node* _root;
};

