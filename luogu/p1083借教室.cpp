#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

#define ll long long 
// #define debug

ll n, m;
vector<ll> vec;
vector<ll> d, s, t;

bool check(ll mid)
{
    vector<ll> diff(n + 3, 0);

    for (int i = 1; i <= mid; i++)
    {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }

    vector<ll> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + diff[i];
    
#ifdef debug
    cout << "sum";
    for (int i = 1; i <= n; i++)
        cout << sum[i] << " ";
    cout << endl;
#endif

    for (int i = 1; i <= n; i++)
        if (sum[i] > vec[i])
            return false;

    return true;
}

int main()
{
    cin >> n >> m;

    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    d.resize(m + 1);
    s.resize(m + 1);
    t.resize(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];
    
    if (check(m))
    {
        cout << 0 << endl;
        return 0;
    }

    ll l = 0, r = m;
    while (l < r)
    {
#ifdef debug
        cout << l << " " << r << endl;
#endif
        ll mid = l + ((r - l) / 2);
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }

    cout << -1 << endl << l << endl;
    
    return 0;
}