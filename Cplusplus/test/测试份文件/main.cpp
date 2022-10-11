#define _CRT_SECURE_NO_WARNINGS 1
#include "XYZ.h"
class B;
class A {
    friend void B::adddd(A* a);

public:
    A()
    {
        i = 0;
    }
private:
    int i;
};

void B::adddd(A* a)
{
    a->i++;
}

int main() 
{
    return 0;
}
