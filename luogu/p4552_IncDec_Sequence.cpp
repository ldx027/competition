#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n;
vector<ll> vec;
vector<ll> diff;

void show(vector<ll> vec)
{
    for (ll i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
}

int main()
{
    cin >> n;

    vec.resize(n);
    diff.resize(n, 0);

    for (ll i = 0; i < n; i++)
        cin >> vec[i];
    
    for (ll i = 1; i < n; i++)
        diff[i] = vec[i] - vec[i - 1];
    
    ll total1 = 0, total2 = 0;
    for (ll i = 0; i < n; i++)
    {
        if (diff[i] > 0)
            total1 += diff[i];
        if (diff[i] < 0)
            total2 -= diff[i];
    }

    // show(vec);
    // show(diff);

    cout << max(total1, total2) << endl;
    cout << abs(total1 - total2) + 1 << endl;

    return 0;
}