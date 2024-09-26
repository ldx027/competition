#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    ll n, x;
    cin >> n >> x;

    vector<ll> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    ll rst = 0;

    if (vec[0] > x)
    {
        rst += vec[0] - x;
        vec[0] = x;
    }

    if (vec[n - 1] > x)
    {
        rst += vec[n - 1] - x;
        vec[n - 1] = x;
    }

    for (int i = 1; i <= n / 2; i++)
    {
        if (vec[i] + vec[i - 1] > x)
        {
            rst += vec[i] - x + vec[i - 1];
            vec[i] = x - vec[i - 1];
        }
        if (vec[n - 1 - i] + vec[n - i] > x)
        {
            rst += vec[n - 1 - i] - x + vec[n - i];
            vec[n - 1 - i] = x - vec[n - i];
        }
    }

    cout << rst << endl;

    return 0;
}