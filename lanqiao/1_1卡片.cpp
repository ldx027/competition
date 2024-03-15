#include <iostream>
#include <cmath>
using namespace std;

int pow(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++)
        rst *= x;
    return rst;
}

int digit(int x, int n)
{
    return x % pow(10, n) / pow (10, n - 1);
}

int  func()
{
    int cards[10];
    for (int i = 0; i < 10; i++) cards[i] = 2021;
    for (int i = 1;;i++)
    {
        for (int j = 1; j <= int(log10(i) + 1); j++)
        {
            if (--cards[digit(i ,j)] < 0) 
            {
                return i - 1;
            }
        }
    }
}

int main()
{
    cout << func() << endl;
    return 0;
}