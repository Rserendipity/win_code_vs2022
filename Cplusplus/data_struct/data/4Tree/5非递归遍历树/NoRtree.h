#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace old
{
	template<class K>
	struct BSTreeNode {
		BSTreeNode<K>* left;
		BSTreeNode<K>* right;
		K key;
		BSTreeNode(const K& key) :key(key), left(nullptr), right(nullptr) {}
	};

	template<class K>
	class BSTree {
		typedef BSTreeNode<K> Node;

	public:
		BSTree()
			:_root(nullptr)
		{}

		bool insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key);
			if (parent->key < key)
			{
				parent->right = cur;
			}
			else
			{
				parent->left = cur;
			}
			return true;
		}

		bool insertR(const K& key)
		{
			return _insertR(_root, key);
		}

		bool erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur != nullptr)
			{
				if (cur->key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					if (cur->left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->right;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->right;
							}
							else
							{
								parent->right = cur->right;
							}
						}
					}
					else if (cur->right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->left;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->left;
							}
							else
							{
								parent->right = cur->left;
							}
						}
					}
					else
					{
						Node* tmp_root = cur; // 将要删除的节点当成根节点
						parent = tmp_root;
						cur = tmp_root->right; // cur节点到根节点的右树去
						while (cur->left != nullptr) // 找到最左边的节点
						{
							parent = cur;
							cur = cur->left;
						}

						// 改变parent的指向，让parent跳过cur
						if (parent->right == cur)
							parent->right = cur->right;
						else
							parent->left = cur->right;

						tmp_root->key = cur->key;
					}
					// 统一 delete
					delete cur;
					return true;
				}
			}
			return false;
		}

		bool eraseR(const K& key)
		{
			return _eraseR(_root, key);
		}

		bool find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->key < key)
				{
					cur = cur->right;
				}
				else if (cur->key > key)
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

		Node* findR(const K& key)
		{
			return _findR(_root, key);
		}

		void inOrder() const
		{
			_inOrder(_root);
			cout << endl;
		}

		const Node* GetRoot() const
		{
			return _root;
		}

	private:
		void _inOrder(const Node* root) const
		{
			if (root != nullptr)
			{
				_inOrder(root->left);
				cout << root->key << " ";
				_inOrder(root->right);
			}
		}

		Node* _findR(Node* _root, const K& key)
		{
			if (_root == nullptr)
				return nullptr;

			if (_root->key < key)
			{
				return _findR(_root->right, key);
			}
			else if (_root->key > key)
			{
				return _findR(_root->left, key);
			}
			else
			{
				return _root;
			}
		}

		bool _insertR(Node*& _root, const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			if (_root->key < key)
			{
				return _insertR(_root->right, key);
			}
			else if (_root->key > key)
			{
				return _insertR(_root->left, key);
			}
			else
				return false;
		}

		bool _eraseR(Node*& _root, const K& key)
		{
			if (_root == nullptr)
				return false;

			if (_root->key < key)
				return _eraseR(_root->right, key);
			else if (_root->key > key)
				return _eraseR(_root->left, key);
			else
			{
				Node* del = _root;
				if (_root->left == nullptr)
				{
					_root = _root->right;
				}
				else if (_root->right == nullptr)
				{
					_root = _root->left;
				}
				else
				{
					Node* cur = _root;
					cur = cur->right;
					while (cur->left != nullptr)
					{
						cur = cur->left;
					}
					std::swap(cur->key, _root->key);
					return _eraseR(_root->right, key);
				}
				delete del;
				return true;
			}
		}

		Node* _root;
	};


}

namespace KV
{
	template<class K, class V>
	struct BSTreeNode {
		BSTreeNode<K, V>* left;
		BSTreeNode<K, V>* right;
		K key;
		V val;
		BSTreeNode(const K& key, const V& val) :key(key), val(val), left(nullptr), right(nullptr) {}
	};

	template<class K, class V>
	class BSTree {
		typedef BSTreeNode<K, V> Node;

	public:
		BSTree()
			:_root(nullptr)
		{}

		bool insert(const K& key,const V& val)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, val);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur != nullptr)
			{
				if (cur->key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					return false;
				}
			}
			cur = new Node(key, val);
			if (parent->key < key)
			{
				parent->right = cur;
			}
			else
			{
				parent->left = cur;
			}
			return true;
		}

		bool erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur != nullptr)
			{
				if (cur->key < key)
				{
					parent = cur;
					cur = cur->right;
				}
				else if (cur->key > key)
				{
					parent = cur;
					cur = cur->left;
				}
				else
				{
					if (cur->left == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->right;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->right;
							}
							else
							{
								parent->right = cur->right;
							}
						}
					}
					else if (cur->right == nullptr)
					{
						if (parent == nullptr)
						{
							_root = cur->left;
						}
						else
						{
							if (parent->left == cur)
							{
								parent->left = cur->left;
							}
							else
							{
								parent->right = cur->left;
							}
						}
					}
					else
					{
						Node* tmp_root = cur; // 将要删除的节点当成根节点
						parent = tmp_root;
						cur = tmp_root->right; // cur节点到根节点的右树去
						while (cur->left != nullptr) // 找到最左边的节点
						{
							parent = cur;
							cur = cur->left;
						}

						// 改变parent的指向，让parent跳过cur
						if (parent->right == cur)
							parent->right = cur->right;
						else
							parent->left = cur->right;

						tmp_root->key = cur->key;
					}
					// 统一 delete
					delete cur;
					return true;
				}
			}
			return false;
		}

		Node* find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->key < key)
				{
					cur = cur->right;
				}
				else if (cur->key > key)
				{
					cur = cur->left;
				}
				else
				{
					return cur;
				}
			}
			return nullptr;
		}

		void inOrder() const
		{
			_inOrder(_root);
			cout << endl;
		}

	private:
		void _inOrder(Node* root) const
		{
			if (root)
			{
				_inOrder(root->left);
				cout << root->key << ":" << root->val << endl;
				_inOrder(root->right);
			}
		}

		Node* _root;
	};
}
