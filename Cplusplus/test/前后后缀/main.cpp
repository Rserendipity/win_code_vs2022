#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()  {
    const string enum_aft[3] = { "@qq.com", "@163.com", "@scuec.com.cn" };

    string input;
    cin >> input;

    auto isFind = input.find('@');
    if (isFind == input.npos) {
        cout << "非法" << endl;
        return -1;
    }

    string pre = input.substr(0, isFind);
    string aft = input.substr(isFind, input.size());

    // 前缀是否合法
    if (pre.size() - 1 >= 6 && pre.size() - 1 <= 20) {
        for (auto ch : pre) {
            if (isalpha(ch) || isdigit(ch)) {
                // 合法字符
            } else {
                cout << "非法" << endl;
                return -1;
            }
        }
    } else {
        cout << "非法" << endl;
        return -1;
    }

    // 后缀
    if (aft.compare(enum_aft[0]) == 0 || aft.compare(enum_aft[1]) == 0 || aft.compare(enum_aft[2]) == 0) {
        // 合法
    } else {
        cout << "非法" << endl;
        return -1;
    }

    cout << "合法" << endl;
    return 0;
}
