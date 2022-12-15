#include <iostream>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        string num;
        for (int ch : s)
        {
            num += to_string(ch - 'a' + 1);
        }
        int sum = 0;
        // cout << num << endl;
        while (k--)
        {
            sum = 0;
            for (int ch : num)
            {
                sum += ch - '0';
            }
            num = to_string(sum);
        }
        return sum;
    }
};
int main()
{

    return 0;
}