#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()  {
    const string enum_aft[3] = { "@qq.com", "@163.com", "@scuec.com.cn" };

    string input;
    cin >> input;

    auto isFind = input.find('@');
    if (isFind == input.npos) {
        cout << "�Ƿ�" << endl;
        return -1;
    }

    string pre = input.substr(0, isFind);
    string aft = input.substr(isFind, input.size());

    // ǰ׺�Ƿ�Ϸ�
    if (pre.size() - 1 >= 6 && pre.size() - 1 <= 20) {
        for (auto ch : pre) {
            if (isalpha(ch) || isdigit(ch)) {
                // �Ϸ��ַ�
            } else {
                cout << "�Ƿ�" << endl;
                return -1;
            }
        }
    } else {
        cout << "�Ƿ�" << endl;
        return -1;
    }

    // ��׺
    if (aft.compare(enum_aft[0]) == 0 || aft.compare(enum_aft[1]) == 0 || aft.compare(enum_aft[2]) == 0) {
        // �Ϸ�
    } else {
        cout << "�Ƿ�" << endl;
        return -1;
    }

    cout << "�Ϸ�" << endl;
    return 0;
}
