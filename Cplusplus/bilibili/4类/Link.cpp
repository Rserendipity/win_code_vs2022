#include "Link.h"
Link::Link()
{
	this->size = 0;
	this->val = 0;
	this->head = NULL;
}

Link::Link(int x)
{
	this->size = 1;
	this->val = x;
	this->head = this;
}
Link::~Link()
{

}
Link::Link(const Link& s)
{

}

void Link::Add(int num)
{

}

void Link::Reverse()
{

}

void Link::Pop()
{
}

int Link::GetHeadVal()
{
	return 0;
}

int Link::GetSize()
{
	return 0;
}
