#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


class Person {
public:
    Person()
    {
        this->num = 0;
    }
    Person(int num)
    {
        this->num = num;
    }
    ~Person()
    {

    }
    // ��ͨ�ĳ�Ա��������ͨ��������ã����Ա����ȴ�������
    // ���û��ʵ��������ͷ��ʲ���
    int getData() 
    {
        return this->data;
    }
    void setData(int val)
    {
        this->data = val;
    }

    // ��̬��Ա����
    // �������У�����ֱ��ͨ����������
    // Ҳ����ͨ������������
    // 
    static int getDataByStatic()
    {
        return data;
    }
    static void setDataByStatic(int num)
    {
        data = num;
    }

 private:
    // static���εĳ�Ա�����Ǿ�̬��
    // �����еĶ��������һ����������̬��Ա�����࣬�����ڶ���
    // ��̬�����ڱ���ʱ�ھͷ����˿ռ�
    // û�д����κζ����ʱ����Ѿ�����
    // ��û�пռ䣬ֻ�����ͣ���̬��Ա������������Ϳռ�
    // ����sizeof������ʱ����static�Ŀռ��С
    // ��ˣ���̬��Ա�������������ڶ��壬���ⲿʵ��
    // 
    static int data; // ��̬��Ա
    int num; // ��ͨ����
};
int Person::data = 100;

void test1()
{
    //// ֱ�ӷ��ʣ�Ҫ��data��Ȩ���ǹ�����
    //cout << Person::data << endl;

    // ʹ����������
    Person p1;
    cout << p1.getData() << endl;
    // ͨ��һ��������ľ�̬���������������ʵ���Ҳ��ı�
    p1.setData(2000);

    Person p2;
    cout << p2.getData() << endl; // 2000���ѱ��ı�
    
    // ͨ����̬�ຯ��ֱ�ӷ�����ľ�̬��Ա
    cout << Person::getDataByStatic() << endl; 

    // ͨ����̬�ຯ��ֱ���޸ľ�̬��Ա
    Person::setDataByStatic(1234);

    // Ҳ����ͨ��
    cout << p2.getDataByStatic() << endl;
}

int main() 
{
    test1();
    return 0;
}
