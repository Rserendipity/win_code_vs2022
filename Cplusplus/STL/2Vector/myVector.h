#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

namespace cjj {
	template<class T>
	class vector {
		typedef T val_type;
		typedef T* iterator;
		typedef const T* const_iterator;

	public:
		vector()
			:_start(nullptr)
			,_finsh(nullptr)
			,_end_of_storge(nullptr)
		{}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finsh = _end_of_storge = nullptr;
			}
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
		
		void push_back(const val_type& x)
		{
			if (_end_of_storge == _finsh)
			{
				size_t sz = size();
				reserve(sz == 0 ? 4 : sz * 2);
			}

			*_finsh++ = x;
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
}