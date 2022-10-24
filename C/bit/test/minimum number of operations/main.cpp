#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

bool isMin(string& s) {
    int sz = s.size();
    for (int i = 0; i < sz - 1; i++) {
        if (s[i] > s[i + 1]) {
            return false;
        }
    }
    return true;
}

void reverse(string& s, int index) {
    int sz = s.size() - 1;
    while (index <= sz) {
        if (s[index] == '0') {
            s[index] = '1';
        }
        else {
            s[index] = '0';
        }
        index++;
    }
}

int findMin(string& s) {
    int sz = s.size();
    int count = 0;

    if (sz == 1) {
        return 0;
    }

    while (!isMin(s)) {
        int index = sz - 1;

        while (index > 0 && s[index] == '1') {
            index--;
        }

        while (index > 0 && s[index] == '0') {
            index--;
        }

        while (index >= 0 && s[index] == '1') {
            index--;
        }

        index++;

        reverse(s, index);
        count++;
    }
    return count;
}

int main()
{
    string input;
    int num = 0;
    int sz = 0;
    cin >> num;
    while (num--) {
        cin >> sz;
        cin >> input;
        cout << findMin(input) << endl;
        input.clear();
    }
    return 0;
}
