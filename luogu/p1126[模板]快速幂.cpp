#include <iostream>
using namespace std;

#define ll long long

ll quickPower(ll a,ll b, ll p)
{
    ll rst = 1;
    ll base = a;
    while (b > 0)
    {
        if (b & 1)
        {
            rst *= base;
            rst %= p;
        }
        base *= base;
        base %= p;
        b >>= 1;
    }

    return rst;
}

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;

    cout << a << "^" << b << " mod " << p << "=" << quickPower(a, b, p) << endl; 

    return 0;
}