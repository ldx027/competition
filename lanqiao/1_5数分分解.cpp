#include <iostream>
#include <cmath>
using namespace std;

int power(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++) rst *= x;
    return x;
}

int digit(int x, int n)
{
    return x % power(10, n) / power(10, n - 1);
}

int main()
{
    for (int a1 = 1; a1 < 2019; a1 += 2)
    {
        for (int i = 0)
        for (int a2 = a1 + 2; a2 < 2019; a2 += 2)
        {
            for (int a3 = a3 + 2; a3 < 2019; a3 += 2)
        }
    }
    // 不写了 烦死
}