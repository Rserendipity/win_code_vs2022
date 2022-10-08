#define _CRT_SECURE_NO_WARNINGS 1
#include "Word.h"

void test1()
{
    Word word;
    string** ch = word.GetCh();
    cout << ch[0][0] << endl;
    cout << ch[1][1] << endl;
}

int main() 
{
    test1();
    //ifstream fin;
    //fin.open("./data/ch0.txt", ios::in);
    //char temp[1000];
    //string s;
    //fin.getline(temp, 999);
    //s += temp;
    //cout << s << endl << s.size();



    return 0;
}
