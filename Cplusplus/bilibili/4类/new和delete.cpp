//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class P {
//private:
//    string name;
//    int a;
//public:
//    P()
//    {
//        cout << "�޲ι���" << endl;
//    }
//    P(string name, int x)
//    {
//        cout << "�вι���" << endl;
//        this->name = name;
//        a = x;
//    }
//    void showNum()
//    {
//        cout << this->a << endl;
//        cout << this->name << endl;
//    }
//    ~P()
//    {
//        cout << "����" << endl;
//    }
//};
///// <summary>
///// new��delete �Լ����� malloc
///// </summary>
//void test1()
//{
//    // malloc�����Ŀռ���Ҫ��ʼ��
//    // ����ֵ��void*��ָ�룬��Ҫǿת
//    // 
//    // malloc������ù��캯��������
//    // free���������������������
//    // ��������Ҫ��ԭ�򣡣���
//    // ���Բ��������ĳ�ʼ��
//    // 
//
//    // ���ܹ��죬�����������޷���ʼ��
//    P* p = (P*)malloc(sizeof(P));
//    free(p);
//}
//
///// <summary>
///// new����������������Լ�����
///// </summary>
//void test2()
//{
//    int* p = NULL;
//    // p = (int*)malloc(sizeof(int));
//    
//    p = new int(10); // ������ͨ����
//    cout << *p << endl;
//    
//    int* arr1 = new int[10]; //��������
//    int* arr2 = new int[100](); // �������鲢��ʼ��Ϊ0
//    int* arr3 = new int[10] {1, 2, 3}; // �������鲢��ʼ��Ϊ1 2 3 0 0 0 0 0 0 0 0 0
//    int* arr4 = new int[10] {0}; // ֻ��ʼ����һ�������౻��ʼ����0
//
//    for (int i = 0; i < 10; i++) {
//        cout << arr2[i] << " ";
//    }
//
//    // ��msvc�¿���ͨ�����룬linux�µ�g++���뱨��
//    // char* ch = new char[32] {"hehe"}; // ��g++���������Ǵ��
//    char* ch = new char[32] {'h', 'e', 'h', 'e'};
//    cout << ch << endl;
//
//    delete p;
//    delete[] arr1;
//    delete[] arr2;
//    delete[] arr3;
//    delete[] arr4;
//    delete[] ch;
//    
//}
//
///// <summary>
///// new�������ռ�
///// </summary>
//void test3()
//{
//    P* p = new P("a123", 10);
//    delete p;
//    auto a = 10;
//    auto p2 = new P("a123", 100);
//    p2->showNum();
//    delete p2;
//}
//
///// <summary>
///// newһ����������
///// </summary>
//void test4()
//{
//    // new �� delete��һ�ԣ�malloc��free��һ��
//    // ���߲����Ի��
//    // �вι����1��3��5��    
//    // 2��4���޲ι���
//    P arr[5]{            // ջ�����ٵ�5���ռ�
//        {"a123", 123},   // �вι���
//        P() ,            // �޲ι���
//        {"aaabbb", 345}, // �вι���
//        {},              // �޲ι���
//        P("dffg", 100) };// �вι���
//
//    P* arr1 = new P[5]; // �������ٵ�5���ռ�,�޲ι���
//    P* arr2 = new P[5]{P("a123", 10)}; // �������ٵ�5���ռ�,ָ�������вι���
//    arr2[0].showNum();
//
//    P* p = new P("a123", 123);
//    void* p1 = p;
//
//    // ���������������
//    // ��Ϊ�������void* ���͵�ָ��
//    // ����delete���p1ָ��Ŀռ䵱��һ����ͨ���ͣ��������ͷſռ�
//    // ������ñ�������������
//    delete p1;  
//
//    // �ͷ���������һ��Ҫ���� [] ������һ���������� 
//    delete[] arr1;
//    delete[] arr2;
//}
//
//int main() 
//{
//    // test1();
//    // test2();
//    // test3();
//    test4();
//    return 0;
//}
