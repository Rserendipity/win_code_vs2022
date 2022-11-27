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

		// �ҵ�����ĵط�
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

		// �жϲ��뵽������
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

		// ����ƽ������ --- �����ĸ߶ȼ�ȥ�����ĸ߶�
		while (parent != nullptr)
		{
			// ���뵽���� --������++
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
				// ������ת
				if (parent->bf == -2 && cur->bf == -1)
				{
					RotateR(parent); // �ҵ�ѡ

				}
				else if (parent->bf == 2 && cur->bf == 1) // ����
				{
					RotateL(parent); // ��ѡ
				}
				else if (parent->bf == -2 && cur->bf == 1) // ����˫��
				{
					RotateLR(parent);
				}
				else if (parent->bf == 2 && cur->bf == -1) // ����˫��
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
				// ��������²����������ӳ���2�ľ���ֵ�������ˣ���˵�������ԭ����������
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

		// ȷ��үү����ת����Ĺ�ϵ
		if (parentParent)
		{
			// үү�ǿգ����жϸ���λ��
			if (parentParent->left == parent)
				parentParent->left = L;
			else
				parentParent->right = L;
		}
		else
		{
			// үүΪ�գ�˵�������ǵ�ǰ�ĸ��ڵ㣬
			_root = L;
		}

		// ������������Ӧ������LR�����ĸ�Ӧ�ø���ΪL
		parent->left = LR;
		parent->parent = L;

		// ����LR��LR��Ϊ�գ������ĸ�ָ��
		if (LR != nullptr)
			LR->parent = parent;

		// ����L��L�ĸ�Ӧ����үү��L����Ӧ���Ǹ�
		L->parent = parentParent;
		L->right = parent;

		// ����ƽ������
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

