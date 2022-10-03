#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
class MakeDrink {
public:
    // Boiling water of pure virtual functions
    virtual void Boil() = 0;

    // Put into the material
    virtual void AddMaterial() = 0;

    // Add a little material
    virtual void AddLittleMaterial() = 0;

    // Production process
    void Process()
    {
        Boil();
        AddMaterial();
        AddLittleMaterial();
    }
};

class Coffee :public MakeDrink {
public:
    virtual void Boil()
    {
        cout << "�ӿ�ˮ" << endl;
    }
    virtual void AddMaterial()
    {
        cout << "�ӿ��ȶ�" << endl;
    }
    virtual void AddLittleMaterial()
    {
        cout << "����" << endl;
    }
};

void MakeSomeDrink(MakeDrink* drink)
{
    drink->Process();
    delete drink;
}


int main()
{
    MakeSomeDrink(new Coffee);
    return 0;
}
