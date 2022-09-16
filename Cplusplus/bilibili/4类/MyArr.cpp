#include "MyArr.h"

MyArr::MyArr()
{
    this->size = 0;
    this->cap = 2;
    this->arr = new int[this->cap] {0};
}

MyArr::MyArr(int arr[], int size)
{
    this->cap = size;
    this->size = size;
    this->arr = new int[size] {0};
    for (int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

MyArr::MyArr(const MyArr& arr)
{
    this->cap = arr.cap;
    this->size = arr.size;
    this->arr = new int[arr.size] {0};
    for (int i = 0; i < arr.size; i++)
        this->arr[i] = arr.arr[i];
}

MyArr::~MyArr()
{
    this->cap = 0;
    this->size = 0;
    delete[] this->arr;
}

void MyArr::PushByPos(int val, int pos)
{
    // 容量过小，增容
    if (this->cap <= this->size)
    {
        this->cap *= 2;
        int* tempArr = new int[this->cap] {0};
        memcpy(tempArr, this->arr, this->size * sizeof(int));
        delete this->arr;
        this->arr = tempArr;
    }
    if (pos < this->size)
    {
        for (int i = this->size - 1; i >= pos; i--)
        {
            this->arr[i + 1] = this->arr[i];
        }
    }
    if (pos > this->size)
        pos = this->size;
    this->arr[pos] = val;
    this->size += 1;
}

void MyArr::PushByHead(int val)
{
    if (this->cap <= this->size)
    {
        this->cap *= 2;
        int* tempArr = new int[this->cap] {0};
        memcpy(tempArr, this->arr, this->size * sizeof(int));
        delete this->arr;
        this->arr = tempArr;
    }
    for (int i = this->size; i >= 0; i--)
    {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[0] = val;
    this->size += 1;
}

void MyArr::PushByTail(int val)
{
    if (this->cap <= this->size)
    {
        this->cap *= 2;
        int* tempArr = new int[this->cap] {0};
        memcpy(tempArr, this->arr, this->size * sizeof(int));
        delete this->arr;
        this->arr = tempArr;
    }
    this->arr[this->size] = val;
    this->size += 1;
}

void MyArr::PopByPos(int pos)
{
    for (int i = pos; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }
    this->size -= 1;
}

void MyArr::PopByHead()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }
    this->size -= 1;
}

void MyArr::PopByTail()
{
    this->size -= 1;
}

void MyArr::ShowAllVal()
{
    for (int i = 0; i < this->size; i++)
        std::cout << this->arr[i] << " ";
    std::cout << std::endl;
}

int MyArr::GetValByPos(int pos)
{
    if (pos >= this->size)
    {
        return -1;
    }
    return this->arr[pos];
}

int MyArr::GetValByHead()
{
    return this->arr[0];
}

int MyArr::GetValByTail()
{
    return this->arr[this->size - 1];
}

int MyArr::GetSize()
{
    return this->size;
}
