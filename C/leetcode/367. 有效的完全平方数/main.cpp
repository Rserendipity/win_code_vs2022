class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long int i;
        for (i = 1; i * i <= num; i++)
            ;
        return (i - 1) * (i - 1) == num;
    }
};