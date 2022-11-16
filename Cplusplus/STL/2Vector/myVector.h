#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

namespace cjj {
	template<class T>
	class vector {
	public:

		typedef T val_type;
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			,_finsh(nullptr)
			,_end_of_storge(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator begin, InputIterator end)
			: _start(nullptr)
			, _finsh(nullptr)
			, _end_of_storge(nullptr)
		{
			while (begin != end)
			{
				push_back(*begin);
				++begin;
			}
		}

		vector(const vector<val_type>& v)
			:_start(nullptr)
			, _finsh(nullptr)
			, _end_of_storge(nullptr)
		{
			vector<val_type> tmp(v.begin(), v.end());
			swap(tmp);
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finsh = _end_of_storge = nullptr;
			}
		}

		void swap(vector<val_type>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finsh, v._finsh);
			std::swap(_end_of_storge, v._end_of_storge);
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finsh;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finsh;
		}

		void reserve(size_t n)
		{
			if (n > capicity())
			{
				size_t sz = size();
				val_type* tmp = new val_type[n];

				if (_start)
				{
					for (size_t i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
				_finsh = _start + sz;
				_end_of_storge = _start + n;
			}
		}

		void resize(size_t n, const val_type& val = val_type())
		{
			if (n < size())
			{
				_finsh = _start + n;
			}
			else
			{
				if (n > capicity())
				{
					reserve(n);
				}

				while (_finsh != _start + n)
				{
					*_finsh++ = val;
				}
			}
		}

		size_t size() const
		{
			return _finsh - _start;
		}

		size_t capicity() const
		{
			return _end_of_storge - _start;
		}
		
		bool empty()
		{
			return _start == _finsh;
		}

		void push_back(const val_type& x)
		{
			if (_end_of_storge == _finsh)
			{
				size_t sz = size();
				reserve(sz == 0 ? 4 : sz * 2);
			}

			*_finsh++ = x;
		}

		void pop_back()
		{
			assert(_start < _finsh);
			--_finsh;
		}

		val_type& front()
		{
			assert(_start < _finsh);
			return *_start;
		}

		val_type& back()
		{
			assert(_start < _finsh);

			return *(_finsh - 1);
		}

		iterator insert(iterator pos, const val_type& val)
		{
			assert(_start <= pos);
			assert(_finsh >= pos);

			if (_finsh == _end_of_storge)
			{
				size_t sz = pos - _start;
				reserve(size() == 0 ? 4 : size() * 2);
				pos = _start + sz;
			}

			iterator tmp = _finsh;
			while (tmp != pos)
			{
				*tmp = *(tmp - 1);
				--tmp;
			}
			*pos = val;
			++_finsh;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(_start <= pos);
			assert(_finsh > pos);

			size_t sz = pos - _start;

			while (pos != _finsh)
			{
				*pos = *(pos + 1);
				++pos;
			}
			--_finsh;
			return _start + sz;
		}

		vector<val_type>& operator=(vector<val_type> v)
		{
			swap(v);
			return *this;
		}

		val_type& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const val_type& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

	private:
		val_type* _start;
		val_type* _finsh;
		val_type* _end_of_storge;
	};

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> ans;
			ans.resize(numRows);
			for (int i = 0; i < numRows; i++) {
				ans[i].resize(i + 1);
				//ans[i][0] = ans[i][ans[i].size() - 1] = 1;
				ans[i].front() = ans[i].back() = 1;
			}
			for (int i = 0; i < numRows; i++) {
				for (int j = 0; j < ans[i].size(); j++) {
					if (ans[i][j] == 0) {
						ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
					}
				}
			}
			return ans;
		}
	};

	void test1()
	{
		vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		v.resize(10, 10);

		for (auto& n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	void test2()
	{
		vector<vector<int>> vv = Solution().generate(7);
		for (auto& v : vv)
		{
			for (auto& n : v)
			{
				cout << n << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void test3()
	{
		vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		cout << v.front() << endl;
		cout << v.back() << endl;
	}

	void test4()
	{
		vector<int> v;
		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);
		v.push_back(50);
		vector<int>::iterator it = std::find(v.begin(), v.end(), 40);
		if (it != v.end())
		{
			v.insert(it, 99);
		}

		it = std::find(v.begin(), v.end(), 40);
		if (it != v.end())
		{
			it = v.erase(it);
		}
		cout << *it << endl;


		for (auto& n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	void test5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 1)
			{
				it = v.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (auto n : v)
		{
			cout << n << " ";
		}
		cout << endl;
	}

	void test6()
	{
		vector<std::string> word;
		word.push_back("111111111");
		word.push_back("111111111");
		word.push_back("ashdkjshdkjfhkajasdf");
		word.push_back("22222222222222222");


		vector<std::string> word2(word);

		for (auto& s : word2)
		{
			cout << s << endl;
		}
	}
}