//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//public:
//    Data():pNum(new int(0)),size(0) 
//    {
//        cout << "�޲�" << endl;
//    }
//    Data(int num, int size):pNum(new int(num)),size(size)
//    {
//        cout << "�в�" << endl;
//    }
//    Data(const Data& d)
//    {
//        cout << "����" << endl;
//        this->pNum = new int(*d.pNum);
//        this->size = d.size;
//    }
//    ~Data()
//    {
//        if (pNum != NULL)
//        {
//            delete pNum;
//            pNum = NULL;
//        }
//        cout << "����" << endl;
//    }
//    Data& operator=(const Data& d)
//    {
//        cout << "����" << endl;
//        this->~Data();
//        this->pNum = new int(*d.pNum);
//        this->size = d.size;
//        return *this;
//    }
//
//    void ShowData()
//    {
//        cout << *this->pNum << " " << this->size << endl;
//    }
//
//private:
//    int* pNum;
//    int size;
//};
//
//void test1()
//{
//    Data d1(10, 20);  // �в�
//    Data d2 = d1;     // �������죬ǳ������ûд�������죩�����ͷ�ʱ���ظ��ͷ�
//    Data d3;          // �޲�
//    // ����Ҫ����������d3Ĭ�������޲ι���ģ�����������ռ䣬��������ص�ʱ�����Ҫ�ͷŵ�����Ȼ���ڴ�й©
//    d3 = d1;          // Ĭ�ϸ�ֵ��ǰ��ֵ��û������=������������ͷ�ʱ���ظ��ͷ�
//    
//    Data d4, d5;
//    d4 = d5 = d3;     // ��������ط��ص����������ã����Կ���������ֵ
//
//    d4.ShowData();
//    d5.ShowData();
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
