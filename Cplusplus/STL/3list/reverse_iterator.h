#pragma once
namespace cjj
{
	template <class iterator, class Ref, class Ptr>
	class __reverse_iterator {
		typedef __reverse_iterator<iterator, Ref, Ptr> self;
	public:
		__reverse_iterator(const iterator& it) 
			:_it(it) 
		{}

		Ref operator*()
		{
			iterator it(_it);
			return *--it;
		}

		Ptr operator->()
		{
			return &operator*();
		}

		self& operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			self tmp(_it--);
			return tmp;
		}

		self& operator--()
		{
			++_it;
			return *this;
		}

		self operator--(int)
		{
			self tmp(_it++);
			return tmp;
		}

		bool operator!=(const self& rit) const
		{
			return rit._it != _it;
		}

	private:
		iterator _it;
	};
}