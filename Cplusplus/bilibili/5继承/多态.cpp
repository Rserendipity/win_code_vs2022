//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Animal {
//public:
//    virtual void Sleep() // �麯��
//    // void Sleep() // ��ͨ��Ա����
//    {
//        cout << "Animal��˯��" << endl;
//    }
//};
//
//class Dog :public Animal {
//public:
//
//    void Sleep()
//    {
//        cout << "Dog��˯��" << endl;
//    }
//};
//
//void test1()
//{
//    // ��̬��
//    // ��̬��̬����̬���࣬������ַ�ڱ����ڼ�ȷ�������������أ����������
//    // ��̬��̬����̬���࣬������ַ������ʱȷ����  ���̳��е��麯������д��
//    // 
//    
//    // ��ϰ���֣�
//    //Dog d;
//    //d.Sleep(); // dog
//    //d.Animal::Sleep(); // animal
//
//    // ���ϼ����ԣ�
//    // ��Animalָ�뱣��Dog�ĵ�ַ�����ʵĽ��ֻ����dog�̳е�Animal����
//    //Animal* p = new Dog;
//    //p->Sleep(); // animal
//
//    // �麯����
//    // ������麯��������������д���û���ָ��Ϳ��Բ�������ĳ�Ա
//    Animal* p = new Dog;
//    p->Sleep(); // dog
//}
//
//int main() 
//{
//    test1();
//    return 0;
//}
