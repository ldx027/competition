#include <iostream>
#include <cmath>
using namespace std;

bool isP(int x)
{
    if (x <= 1)
        return false;
    if (x == 2 || x == 3)
        return true;
    int n = x % 6;
    if (n % 2 == 0 || n == 3)
        return false;

    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    long long N;
    cin >> N;

    long long beg = 2, maxLen = 0;
    if (isP(N))
    {
        cout << 1 << endl << N << endl;
        return 0;
    }
    for (long long i = 2; i < sqrt(N); i++)
    {
        long long num = i;
        long long j = i;
        while (N % num == 0)
        {
            num *= ++j;
        }
        if (--j - i + 1 > maxLen)
        {
            beg = i;
            maxLen = j - i + 1;
        }
    }

    cout << maxLen << endl;
    bool have = 0;
    for (int i = 0; i < maxLen; i++)
    {
        if (have)
            cout << "*";
        cout << beg + i;
        have = 1;
    }

    return 0;
}