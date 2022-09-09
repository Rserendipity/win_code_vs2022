#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class P {
private:
    int a;
public:
    P(int x)
    {
        cout << "�вι���" << endl;
        a = x;
    }
    ~P()
    {
        cout << "����" << endl;
    }
};
/// <summary>
/// new��delete �Լ����� malloc
/// </summary>
void test1()
{
    // malloc�����Ŀռ���Ҫ��ʼ��
    // ����ֵ��void*��ָ�룬��Ҫǿת
    // 
    // malloc������ù��캯��������
    // free���������������������
    // ��������Ҫ��ԭ�򣡣���
    // ���Բ��������ĳ�ʼ��
    // 

    // ���ܹ��죬�����������޷���ʼ��
    P* p = (P*)malloc(sizeof(P));
    free(p);
}

/// <summary>
/// new����������������Լ�����
/// </summary>
void test2()
{
    int* p = NULL;
    // p = (int*)malloc(sizeof(int));
    
    p = new int(10); // ������ͨ����
    cout << *p << endl;
    
    int* arr1 = new int[10]; //��������
    int* arr2 = new int[100](); // �������鲢��ʼ��Ϊ0
    int* arr3 = new int[10] {1, 2, 3}; // �������鲢��ʼ��Ϊ1 2 3 0 0 0 0 0 0 0 0 0
    int* arr4 = new int[10] {0}; // ֻ��ʼ����һ�������౻��ʼ����0

    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << " ";
    }

    // ��msvc�¿���ͨ�����룬linux�µ�g++���뱨��
    // char* ch = new char[32] {"hehe"}; // ��g++���������Ǵ��
    char* ch = new char[32] {'h', 'e', 'h', 'e'};
    cout << ch << endl;

    delete p;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] ch;
    
}

int main() 
{
    // test1();
    test2();
    return 0;
}
