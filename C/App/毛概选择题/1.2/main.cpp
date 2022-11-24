#include "qustion.h"


int main()
{
    qustion q;

    string a;
    while (true)
    {
        cout << q.GetOneQustion();
        std::cin >> a;
    }

    return 0;
}
