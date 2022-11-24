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
        // 六行，题目，四个选项，一行空行
        // 读取题目
        fq.getline(tmp[0], 10000);
        // 选项
        fq.getline(tmp[1], 10000);
        fq.getline(tmp[2], 10000);
        fq.getline(tmp[3], 10000);
        fq.getline(tmp[4], 10000);
        // 空格
        fq.getline(tmp[5], 10000);

        // 输出题目，保存题目到文件
        fqu << tmp[0] << '\n';

        // 读取当前题目的正确选项从选项里读哪一个是正确的，一行一个
        fans >> ans;
        index = ans[ans.size() - 1] - 'A' + 1;
        fyes << (tmp[index] + 2) << "\n"; // tmp是上面读取的选项，往后偏移两个字节，去掉A:这样的内容

        // 写入错误的选项
        for (int i = 1; i <= 4; i++)
        {
            if (index != i) // 不为正确选项，就写入到错误文件里
            {
                ferr << (tmp[i] + 2) << "\n";
            }
        }
        ferr << "\n";
        memset(tmp, 0, 6 * 10000); // 清空tmp数据
    }

    fq.close();
    fans.close();
    fqu.close();
    ferr.close();
    fyes.close();

    return 0;
}
