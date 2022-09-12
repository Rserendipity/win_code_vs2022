#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


class Data {
public:
    Data()
    {
        // this ָ��ָ��ĵ�ǰ����ĳ�Ա
        // ������thisָ��ָ��Ķ�Ӧ�ı����Ϳ����ҵ���Ӧ�����ֵ
        this->data = 10;
        this->a = 1;
    }
    void setNum(int num)
    {
        this->data = num;
    }
    int getNum()
    {
        return this->data;
    }
    // �ں������ұ߼���const�Ϳ��Ը��߱�����������һ��������
    // ע������const�ŵ���ߵ�ʱ���ʾ���Ƿ���ֵ��һ������
    // ������������ں����ڲ����ĳ�Ա�����ֵ
    // ������������ mutable ʱ�������ڳ������ڸ���
    void printData() const 
    {
        // this->data = 100; // err �����Ѿ����������˳��������ڲ��������޸�
        this->a = 100l; // �����޸ģ�a�� mutable ����
        cout << this->data << endl;
        cout << this->a << endl;
    }
    Data& getThis()
    {
        return *this;
    }
private:
    // �Ǿ�̬��Ա����ֱ�Ӵ洢������
    // ���ݺͷ�������װ��һ�𣬵��������Ƿֿ��洢��
    // ÿ�������ж����ķǾ�̬����
    // ���еĶ��������еķ���
    // 
    int data;

    // a���������ڳ������б�����
    mutable int a;
};
/// <summary>
/// thisָ��
/// </summary>
void test1()
{
    Data d1;
    d1.setNum(10);
    cout << d1.getNum() << endl;

    Data d2;
    d1.setNum(20);
    cout << d1.getNum() << endl;

    Data d3;
    d1.setNum(30);
    cout << d1.getNum() << endl;

    cout << &d3.getThis().getThis().getThis() << endl;

    auto d4 = new Data;
    d4->setNum(100);
    cout << d4->getThis().getNum() << endl;

}

/// <summary>
/// const���γ�Ա����
/// </summary>
void test2()
{
    Data d1;
    d1.printData();
}

/// <summary>
/// const����
/// </summary>
void test3()
{
    // ������ֻ�ܵ���const���εĺ���
    // ��ͨ�ĳ�Ա��������������Ϊ�ǲ���ȫ��
    // ���ܷ����Գ�Ա���޸ģ����������ֲ������޸�
    // 
    const Data d1; // ����ʱ��a��ֵʱ1
    // d1�е�a��mutable��������print�������޸�������ֵ
    d1.printData(); // ��ӡ���a��ֵʱ100
}

int main() 
{
    // test1();
    // test2();
    test3();
    return 0;
}
