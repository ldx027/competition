#include <iostream>
#include <cmath>
using namespace std;

#define ull unsigned long long

ull func(ull x, int k)
{
    ull rst = 1;

    for (ull i = 2; i <= sqrt(x); i++)
    {
        bool flg = true;
        for (ull j = 2; j < i; j++)
            if (i % j == 0)
            {
                flg = false;
                break;
            }

        if (!flg)
            continue;

        int cnt = 0;
        while (x % i == 0)
        {
            x /= i;
            cnt++;
        }

        if (cnt >= k)
            rst *= pow(i, cnt);
    }

    return rst;
}

int main()
{
    int q;
    cin >> q;

    ull n, k;
    while (q--)
    {
        cin >> n >> k;
        cout << func(n, k) << endl;
    }

    return 0;
}