#pragma once
#include "reverse_iterator.h"
#include <iostream>
#include <assert.h>
using std::cout;
using std::endl;

namespace cjj
{
	template<class T>
	struct ListNode {
		T val;
		ListNode<T>* pre;
		ListNode<T>* next;
		ListNode(const T& val = T()) :val(val), pre(nullptr), next(nullptr) {}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef ListNode<T> node_type;
		typedef __list_iterator<T, Ref, Ptr> self;
		
		__list_iterator(node_type* node) :_node(node) {}

		Ref operator*()
		{
			return _node->val;
		}

		Ptr operator->()
		{
			return &operator*();
		}

		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(_node);
			_node = _node->next;
			return tmp;
		}
		self& operator--()
		{
			_node = _node->pre;
			return *this;
		}
		self operator--(int)
		{
			self tmp(_node);
			_node = _node->pre;
			return tmp;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}
		bool operator==(const self& it) const
		{
			return _node == it._node;
		}

		node_type* _node;
	};

	template<class T>
	class list {
		typedef ListNode<T> node_type;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		typedef __reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef __reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

		iterator begin()
		{
			return iterator(_head->next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		list()
			:_head(new node_type())
		{
			_head->pre = _head;
			_head->next = _head;
		}

		template<class InputIterator>
		list(InputIterator begin, InputIterator end)
			:_head(new node_type())
		{
			_head->pre = _head;
			_head->next = _head;

			while (begin != end)
			{
				push_back(*begin);
				++begin;
			}
		}

		list(const list& lt)
			:_head(new node_type())
		{
			_head->pre = _head;
			_head->next = _head;
			list<T> tmp(lt.begin(), lt.end());
			std::swap(tmp._head, _head);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			node_type* tmp = _head->next;
			while (tmp != _head)
			{
				tmp = tmp->next;
				delete tmp->pre;
			}
			_head->next = _head;
			_head->pre = _head;
		}

		void push_back(const T& val)
		{
			/*node_type* newNode = new node_type(val);
			newNode->next = _head;
			newNode->pre = _head->next;
			_head->pre->next = newNode;
			_head->pre = newNode;*/

			insert(end(), val);
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(const iterator pos, const T& val)
		{
			node_type* tmp = pos._node;
			node_type* newNode = new node_type(val);
			newNode->next = tmp;
			newNode->pre = tmp->pre;
			tmp->pre->next = newNode;
			tmp->pre = newNode;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			node_type* cur = pos._node;
			node_type* pre = cur->pre;
			node_type* next = cur->next;

			pre->next = next;
			next->pre = pre;
			delete cur;

			return iterator(next);
		}

	private:
		node_type* _head;
	};

	void test1()
	{
		list<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		l.push_back(40);

		const list<int>& l2(l);

		list<int>::const_iterator it = l2.begin();
		while (it != l2.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	void test2()
	{
		list<int> l1;
		l1.push_back(10);
		l1.push_back(20);
		l1.push_back(30);
		l1.push_back(40);

		list<int>::iterator it = l1.begin();
		l1.insert(it, 99);
		++it;
		++it;

		l1.insert(it, 100);

		for (auto& n : l1) {
			cout << n << " ";
		}

		cout << endl;
	}

	void test3()
	{
		list<int> l1;
		l1.push_back(10);
		l1.push_back(20);
		l1.push_back(30);
		l1.push_back(40);

		for (auto n : l1)
		{
			cout << n << " ";
		}

		cout << endl;

		auto it = l1.begin();
		++it;
		it = l1.erase(it);
		it = l1.erase(it);
		it = l1.erase(it);

		for (auto n : l1)
		{
			cout << n << " ";
		}
		cout << endl;

		l1.clear();
	}

	void test4()
	{
		list<int> l1;
		l1.push_back(10);
		l1.push_back(20);
		l1.push_back(30);
		l1.push_back(40);

		list<int> l2(l1);

		for (auto n : l2)
		{
			cout << n << " ";
		}
		l2.pop_back();
		l2.pop_front();
		for (auto n : l2)
		{
			cout << n << " ";
		}
	}

	void test5()
	{
		ListNode<int> n(10);
		list<ListNode<int>> l1;
		l1.push_back(n);
		l1.push_back(n);
		l1.push_back(n);
		l1.push_back(n);

		auto it = l1.begin();
		while (it != l1.end())
		{
			cout << it->val << endl;
			++it;
		}

	}
	
	void test6()
	{
		list<int> l1;
		l1.push_back(10);
		l1.push_back(20);
		l1.push_back(30);
		l1.push_back(40);
		list<int>::reverse_iterator it = l1.rbegin();
		
		while (it != l1.rend())
		{
			cout << *it << " ";
			++it;
		}

	}

}
