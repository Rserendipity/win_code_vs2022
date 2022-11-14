#pragma once
#include <iostream>
#include <cstring>
#include <cassert>

using std::cout;
using std::endl;


namespace cjj
{

	class string 
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}

		// 构造
		string(const char* s = "")
			:_size(strlen(s))
			,_cap(_size)
		{
			_str = new char[_cap + 1];
			strcpy(_str, s);
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_cap, s._cap);
		}
		// 拷贝构造
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _cap(0)
		{
			string tmp(s._str);
			swap(tmp);
		}
		// 析构
		~string()
		{
			if (_str != nullptr)
			{
				delete[] _str;
				_size = 0;
				_cap = 0;
			}
		}


		// 只需要调整大小，n <= _cap，啥也不干
		void reserve(size_t n)
		{
			if (n > _cap)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_cap = n;
			}
		}

		// 调整大小，并初始化
		void resize(size_t n, char val = 0)
		{
			if (n <= _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _cap)
				{
					reserve(n);
				}

				memset(_str + _size, val, n - _size);
				_size = n;
				_str[_size] = '\0';
			}
		}

		// 尾增
		void push_back(const char ch)
		{
			if (_cap == _size)
			{
				reserve(_cap == 0 ? 4 : _cap * 2);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capcity() const
		{
			return _cap;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		bool empty() const
		{
			return _size == 0;
		}

		char& back()
		{
			assert(!empty());
			return _str[0];
		}

		const char& back() const
		{
			assert(!empty());
			return _str[0];
		}

		char& front()
		{
			assert(!empty());
			return _str[_size - 1];
		}

		const char& front() const
		{
			assert(!empty());
			return _str[_size - 1];
		}

		string& insert(size_t pos, const char& ch)
		{
			assert(pos <= _size);
			if (_size == _cap)
			{
				reserve(_cap == 0 ? 4 : _cap * 2);
			}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				end--;
			}

			_str[pos] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);

			if (_cap < _size + len)
			{
				reserve(_cap + len);
			}

			size_t end = _size + len;
			while (end > pos + len - 1)
			{
				_str[end] = _str[end - len];
				end--;
			}

			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		string& insert(size_t pos, const string& s)
		{
			assert(pos <= _size);
			insert(pos, s._str);
			return *this;
		}

		string& erase(size_t begin, size_t n = npos)
		{
			assert(begin < _size);

			if (n > _size - begin)
			{
				_size = begin;
				_str[begin] = '\0';
			}
			else
			{
				while (begin + n < _size)
				{
					_str[begin] = _str[begin + n];
					begin++;
				}
				_str[begin] = '\0';
				_size -= n;
			}
			return *this;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		string& operator+=(const char& ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* s)
		{
			size_t sz = strlen(s);
			reserve(sz + _size);
			strcpy(_str + _size, s);
			_size += sz;
			return *this;
		}

		string& operator+=(const string& s)
		{
			*this += s.c_str();
			return *this;
		}
		
		const static size_t npos;
	private:
		char* _str;
		size_t _size;
		size_t _cap;
	};
	const size_t string::npos = -1;

	std::ostream& operator<<(std::ostream& out, cjj::string& s)
	{
		for (auto& ch : s)
		{
			out << ch;
		}
		return out;
	}

	void test1()
	{
		string s;
		s.push_back('1');
		s.push_back('2');
		s.push_back('3');
		s.push_back('4');


		for (auto ch : s)
		{
			cout << ch;
		}
		cout << endl;

		string s2("hello world");

		for (auto ch : s2)
		{
			cout << ch;
		}
		cout << endl;
	}

	void test2()
	{
		string s("123123");
		cout << s << endl;

		s.resize(100, 'x');
		cout << s << endl;
	}

	void test3()
	{
		string s;
		string s2("2222");
		s += 'a';
		s += "bcdef";
		s.reserve(20);
		s += "111";
		s += s2;
		cout << s << endl;
	}

	void test4()
	{
		string s("abc");
		string s2("bbbb");
		s.insert(0, 'x');
		cout << s << endl;

		s.insert(0, "111");
		cout << s << endl;

		s.insert(2, "www");
		cout << s << endl;

		s.insert(2, s2);
		cout << s << endl;

	}

	void test5()
	{
		string s("abcdefg");
		cout << s << endl;
		s.erase(2, 2);
		cout << s << endl;
		s.erase(2);
		cout << s << endl;
		s.push_back('a');
		s.push_back('a');
		s.push_back('a');
		cout << s << endl;
		s.erase(0);
		cout << s << endl;
		s.insert(0, "aaaaa");
		cout << s << endl;
	}
}