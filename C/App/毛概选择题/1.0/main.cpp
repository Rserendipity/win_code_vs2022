#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fq("./data/single/q.txt", ios::in);
    fstream fans("./data/single/ans.txt", ios::in);

    fstream fqu("./data/qu.txt", ios::out);
    fstream ferr("./data/err.txt", ios::out);
    fstream fyes("./data/yes.txt", ios::out);

    string ans;

    int index = 0;
    char(*tmp)[10000] = new char[6][10000];
    while (!fq.eof())
    {
        // ���У���Ŀ���ĸ�ѡ�һ�п���
        // ��ȡ��Ŀ
        fq.getline(tmp[0], 10000);
        // ѡ��
        fq.getline(tmp[1], 10000);
        fq.getline(tmp[2], 10000);
        fq.getline(tmp[3], 10000);
        fq.getline(tmp[4], 10000);
        // �ո�
        fq.getline(tmp[5], 10000);

        // �����Ŀ��������Ŀ���ļ�
        fqu << tmp[0] << '\n';

        // ��ȡ��ǰ��Ŀ����ȷѡ���ѡ�������һ������ȷ�ģ�һ��һ��
        fans >> ans;
        index = ans[ans.size() - 1] - 'A' + 1;
        fyes << (tmp[index] + 2) << "\n"; // tmp�������ȡ��ѡ�����ƫ�������ֽڣ�ȥ��A:����������

        // д������ѡ��
        for (int i = 1; i <= 4; i++)
        {
            if (index != i) // ��Ϊ��ȷѡ���д�뵽�����ļ���
            {
                ferr << (tmp[i] + 2) << "\n";
            }
        }
        ferr << "\n";
        memset(tmp, 0, 6 * 10000); // ���tmp����
    }

    fq.close();
    fans.close();
    fqu.close();
    ferr.close();
    fyes.close();

    return 0;
}
