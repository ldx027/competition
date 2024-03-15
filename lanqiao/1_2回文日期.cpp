#include <iostream>
using namespace std;

int pow(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++) rst *= x;
    return rst;
}

int digit(int x, int n)
{
    return x % pow(10, n) / pow(10, n - 1);
}

bool isRen(int y)
{
    return y % 4 == 0 && y % 100 != 0;
}

int main()
{
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int data;
    cin >> data;
    for (int y = data / 10000; y < 10000; y++)
    {
        days[1] = isRen(y) ? 29 : 28;
        for (int m = data % 10000 / 100; m < 13; m++)
        {
            for (int d = data % 100 + 1; d)
        }
    }
}