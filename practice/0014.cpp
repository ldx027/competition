#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int base, power;
    cin >> base >> power;

    ll ans = 1;

    while (power)
    {
        if (power & 1)
            ans *= base;
        power >>= 1;
        base *= base;
    }

    cout << ans << endl;

    return 0;
}