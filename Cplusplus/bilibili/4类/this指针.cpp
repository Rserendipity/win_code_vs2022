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
    }
    void setNum(int num)
    {
        this->data = num;
    }
    int getNum()
    {
        return this->data;
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

int main() 
{
    test1();
    return 0;
}
