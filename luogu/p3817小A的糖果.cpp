#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    int n, x;
    cin >> n >> x;

    vector<ll> vec(n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    ll ans = 0;

    if (vec[n - 1] + vec[n - 2] > x)
    {
        ans += vec[n - 1] + vec[n - 2] - x;
        vec[n - 2] = x - vec[n - 1];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (vec[i] + vec[i - 1] > x)
        {
            ans += vec[i] + vec[i - 1] - x;
            vec[i] = x - vec[i - 1];
        }
    }

    cout << ans << endl;

    return 0;
}