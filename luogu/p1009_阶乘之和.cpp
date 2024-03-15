#include <iostream>
#include <cmath>
#define Digit 100
using namespace std;

int digit(int x, int n) { return x % int(pow(10, n) + 0.1) / pow(10, n - 1); }

void clear(int *num) { for (int i = 0; i < Digit; i++) num[i] = -1; }

void change(int x, int *rst)
{
    clear(rst);
    if (x == 0) rst[0] = 0;
    for (int i = 0; i < log10(x) + 1; i++)
    {
        rst[i] = digit(x, i + 1);
    }
}

void carry(int *num)
{
    for (int i = 0; i < Digit && num[i] >= 0; i++)
    {
        if (num[i] > 9)
        {
            num[i + 1] = num[i] / 10 + (num[i + 1] > 0 ? num[i + 1] : 0);
            num[i] %= 10;
        }
    }
}

void sum(const int *a, const int *b, int *rst)
{
    clear(rst);
    for (int i = 0; i < Digit && (a[i] >= 0 || b[i] >= 0); i++)
    {
        rst[i] = (a[i] > 0 ? a[i] : 0) + (b[i] > 0 ? b[i] : 0);
    }
    carry(rst);
}

void mul(const int *a, int b, int *rst)
{
    clear(rst);
    for (int i = 0; i < Digit && a[i] >= 0; i++)
    {
        rst[i] = a[i] * b;
    }
    carry(rst);
}

void mul(const int *a, const int *b, int *rst)
{
    clear(rst);
    for (int i = 0; i < Digit && a[i] >= 0; i++)
    {
        rst[i] = 0;
        for (int j = 0; j < Digit && b[j] >= 0; j++)
        {
            rst[i] += a[i] * b[j] * (pow(10, j) + 0.1);
        }
    }
    carry(rst);
}

void copy(const int *source, int *target)
{
    clear(target);
    for (int i = 0; i < Digit && source[i] >= 0; i++)
    {
        target[i] = source[i];
    }
}

void print(const int *num)
{
    int i;
    for (i = 0; i < Digit && num[i] >= 0; i++);
    for (i-- ; i >= 0; i--) cout << num[i];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int rst[Digit];
    change(1, rst);

    int lastItem[Digit];
    change(1, lastItem);
    int mulRst[Digit];
    int sumRst[Digit];

    for (int i = 2; i <= n; i++)
    {
        mul(lastItem, i, mulRst);
        sum(mulRst, rst, sumRst);
        copy(sumRst, rst);
        copy(mulRst, lastItem);
    }
    print(rst);

    return 0;
}