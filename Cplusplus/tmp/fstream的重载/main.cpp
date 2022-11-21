#define _CRT_SECURE_NO_WARNINGS 1
#include <fstream>

using namespace std;

class Data
{
    friend ofstream& operator<<(ofstream& fout, const Data& d);

private:
    int _year;
    int _month;
};

ofstream& operator<<(ofstream& fout, const Data& d)
{
    fout << d._month << d._year;
    return fout;
}
int main()
{

    return 0;
}
