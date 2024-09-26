#include <iostream>
#include <cmath>
using namespace std;

#define ull unsigned long long

ull quickPow(ull x, ull pow)
{
    ull rst = 1;
    ull base = x;
    while (pow)
    {
        if (pow % 2)
            rst *= base;
        pow >>= 1;
        base *= base;
    }
    return rst;
}

ull bin(ull L, ull R, ull n)
{
    // cout << L << " " << R << endl;
    if (L > R) return -1;
    if (L == R) return L;

    ull mid = L + ((R - L) >> 1);
    ull dig = log10(quickPow(mid, mid)) + 1;
    // cout << dig << endl;

    if (dig >= n)
        return bin(L, mid, n);
    else if (dig < n)
        return bin(mid + 1, R, n);
}

int main()
{
    ull n;
    cin >> n;

    for (int i = 1; i < 15; i++)
        cout << i << " " << log10(quickPow(i, i)) + 1 << "\n";

    for (int i = 1; i <= 15; i++)
        cout << i << " " << bin(1, i + 1, i) << endl;

    return 0;
}