//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Data {
//     friend ostream& operator<<(ostream& out, Data& d);
//public:
//    Data() :a(0), b(0) 
//    {
//        cout << "�޲�" << endl;
//    }
//    Data(int a, int b):a(a),b(b)
//    {
//        cout << "�в�" << endl;
//    }
//    Data(const Data& d)
//    {
//        this->a = d.a;
//        this->b = d.b;
//        cout << "��������" << endl;
//    }
//    ~Data()
//    {
//        cout << "����" << endl;
//    }
//    
//    //ostream& operator<<(ostream& out)
//    //{
//    //    out << this->a;
//    //    return out;
//    //}
//
//    // ����ǰ������
//    // �����������ã����Խ��е���
//    Data& operator++()
//    {
//        this->a++;
//        this->b++;
//        return *this;
//    }
//
//    // ���غ����Լ�
//    // �����������صĽ�����������ã��ǹ̶���ֵ�����ܽ��е���
//    Data operator++(int)
//    {
//        // �ȱ�����ǰ��ֵ���ѵ�ǰ��ֵ�Ӽӣ����ر��ݵ�ֵ
//        Data temp = *this;
//        this->a++;
//        this->b++;
//        return temp;
//    }
//
//    Data& operator--()
//    {
//        this->a--;
//        this->b--;
//        return *this;
//    }
//
//    // ���غ����Լ�
//    // �����������صĽ�����������ã��ǹ̶���ֵ�����ܽ��е���
//    Data operator--(int)
//    {
//        // �ȱ�����ǰ��ֵ���ѵ�ǰ��ֵ��һ�����ر��ݵ�ֵ
//        Data temp = *this;
//        this->a--;
//        this->b--;
//        return temp;
//    }
//
//private:
//    int a;
//    int b;
//};
//// �������
//ostream& operator<<(ostream& out, Data& d)
//{
//    out << "a = " << d.a << endl;
//    out << "b = " << d.b << endl;
//    return out;
//}
//
///// <summary>
///// ����++��--
///// </summary>
//void test1()
//{
//    // �������Լ����������֣�һ����ǰ�ã�һ���Ǻ���
//    // Ϊ�˽�����������⣬����ʹ��ռλ������������
//    // operator++(a)     ---->  ++a;
//    // operator++(a,int) ---->  a++; 
//    // 
//    Data d(10, 20);
//    //cout << "ԭ����ֵ" << endl;
//    //cout << d << endl;
//
//    ////cout << "��������ֵ" << endl;
//    ////cout << d++ << endl; // errǰ��++��������ã����üӼӽ����ֵ
//    //
//    //cout << "�������ֵ" << endl;
//    //cout << d << endl;
//
//    //cout << "ǰ������ֵ" << endl;
//    //cout << ++d << endl;
//    //
//    //cout << "�������ֵ" << endl;
//    //cout << d << endl;
//    
//    cout << d << endl;
//    d++; // ���üӼӵĽ����ֵ���������ã����Ա����Ƚ������ֵ
//    cout << d << endl;
//    d--;
//    cout << d << endl;
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
