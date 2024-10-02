#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> vec;
vector<ll> d, s, t;
vector<ll> diff;
vector<ll> sum;

bool check(ll mid, ll n)
{
    diff.clear();
    diff.resize(n + 1, 0);
    sum.clear();
    sum.resize(n + 1, 0);
    for (ll i = 1; i <= mid; i++)
    {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }

    for (ll i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + diff[i];
        if (sum[i] > vec[i])
            return false;
    }

    return true;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vec.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];
    
    d.resize(m + 1);
    s.resize(m + 1);
    t.resize(m + 1);

    for (ll i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];
    
    if (check(m, n))
    {
        cout << 0;
        return 0;
    }
    
    ll l = 1, r = m;
    while (l < r)
    {
        // cout << l << " " << r << endl;
        ll mid = l + ((r - l) >> 1);
        if (check(mid, n))
            l = mid + 1;
        else
            r = mid;
    }

    cout << -1 << endl;
    cout << l << endl;

    return 0;
}