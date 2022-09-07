#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

// �����Լ���ʼ��
void fun1()
{
    // ������һ��������4���ֽڵĿռ�
    // ���þͿ��Ը��������ȡһ������
    int a = 0;
    // ��ֵΪ���ã���ֵ��ȡ��ַ
    // ���ñ����ʼ��
    // ���������ɱ��޸�
    // ���ò��Ὺ�ٿռ�
    // b��ȫ�ȼ���a
    int& b = a; // ���b����a������

    int temp = 10;

    // ����ĺ����ǰ�temp��ֵ��b
    // ���ǰ�b�ĳɶ�temp������
    b = temp;

    cout << a << endl;
    cout << b << endl;

    // a��b�ĵ�ַ��ȫһ��
    cout << "*a = " << &a << endl;
    cout << "*b = " << &b << endl;
}

// ���������
void fun2()
{
    int arr[] = { 1, 2, 3, 4, 5 };

    // ��arrȡ����
    // ����ָ�������Ԫ�ظ���
    // ��Ҫ�ã�����ȷ��parr�����ȼ�
    // []�����ȼ�����&
    // �������һ����������
    int(&parr)[5] = arr;

    // ��typedef������ȡ����
    // �����µ�����ȡ��ԭ���Ͷ�������
    typedef int Arr_t[5];
    // Arr_t���͵�����
    Arr_t& my_arr_t = arr;

    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << parr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << my_arr_t[i] << " ";
    }
    cout << endl;
}

// ������������
void my_swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void my_swap2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void my_swap3(int& a, int& b)
{
    // ����ʱ���Ƕ�ԭ������ʹ��
    int temp = a;
    a = b;
    b = temp;
}
// ������Ϊ�����Ĳ���
void fun3()
{
    int a = 10;
    int b = 20;
    cout << a << " " << b << endl;

    // û�б��ı�
    my_swap1(a, b);
    cout << a << " " << b << endl;
    // �ɹ�����  --->  ָ��
    my_swap2(&a, &b);
    cout << a << " " << b << endl;
    // �ɹ�����  --->  ����
    my_swap3(a, b);
    cout << a << " " << b << endl;
}

int& myFunc1()
{
    int num = 10;
    static int num1 = 20;
    // �﷨��ȷ����
    // ���ص���һ���Ѿ������ٵľֲ�����
    // ��Ұָ������
    // return num; // warning

    return num1;
}
// ������Ϊ�����ķ���ֵ
void fun4()
{
    // ����ֵ�����õ�ʱ��
    // ��Ҫֱ�Ӷ���һ��������ֱ�ӳ�ʼ��
    // ԭ�����ñ���Ҫ��ʼ��
    int& ret = myFunc1();
    cout << ret << endl;
}

int& myFunc2()
{
    static int num = 10;
    return num;
}
// ������Ϊ��ֵʱ���䷵��ֵһ��Ҫ������
void fun5()
{
    cout << myFunc2() << endl;
    // ���ص���һ������
    // ����ʵ���������Ƕ�num��ֵ
    myFunc2() = 2000;

    // ���������ӡ����num��ǰ��ֵ��2000
    cout << myFunc2() << endl;
}

// ���õı��ʣ�����ָ��
void fun6()
{
    int data = 10;
    int& a = data;
    a = 100; // �൱�� data = 100;
    // �ڲ��Ķ��壺int*const b = &data;
    // �ڲ���ʹ�ã�*b = 100;
    // �����const������b������b���ɱ��޸�
}

// C���ԣ�ȡ��ַ
void myStr1(char** str)
{
    *str = (char*)calloc(sizeof(char) * 10, 1);
    strcpy(*str, "hello");
}
// C++������
void myStr2(char*& str)
{
    str = (char*)calloc(sizeof(char) * 10, 1);
    strcpy(str, "hello");
}
// ָ������
void fun7()
{
    // ��ָ�����ȡ����
    int a = 10;
    int b = 20;
    int* pa = &a;
    int*& ra = pa;
    // type    &  name  =   value;
    // int*    &  ra    =   &pa  ;

    // C���ȡ������ַ
    char* str = NULL;
    myStr1(&str);
    cout << str << endl;
    free(str);

    // C++������ã��൱�ں����ڲ�ʹ�õľ���str����
    myStr2(str);
    cout << str << endl;
    free(str);
}

typedef struct stu {
    int age;
    char name[20];
} Stu;
void printStu1(Stu s)
{
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
void printStu2(Stu& s)
{
    // s.age = 100 //��ͨ���ÿ��Ա��޸�
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
void printStu3(const Stu& s)
{
    // s.age = 100; //err �����ò������޸�
    cout << sizeof(s) << endl;
    cout << s.age << s.name << endl;
}
// ��������
void fun8()
{
    Stu s = { 10, "c" };
    printStu1(s); // ֵ���ݣ�������
    printStu2(s); // ֱ�����ã�����Ϊ�βο��ٿռ�
    printStu3(s); // �����ã��ں����ڲ��ᱻ�޸�
}

// ����ֵ����
void fun9()
{
    // int &num = 10; //10 ��һ��������������const����
    const int& num = 10; //��ȷ
    cout << "num = " << num << endl;
}
int main()
{
    // fun1();
    // fun2();
    // fun3();
    // fun4();
    // fun5();
    // fun6();
    // fun7();
    // fun8();
    fun9();
    return 0;
}
