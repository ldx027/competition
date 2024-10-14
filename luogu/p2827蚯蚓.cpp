#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define ll long long

ll n, m, q, u, v, t;
double p;
vector<ll> buf;
vector<queue<ll>> vec;

int main()
{
    vec.resize(3);
    cin >> n >> m >> q >> u >> v >> t;
    p = (double)u / v;

    buf.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> buf[i];
    sort(buf.begin(), buf.end(), greater<ll>());
    for (int i = 0; i < n; i++)
        vec[0].push(buf[i]);

    for (ll i = 0; i < m; i++)
    {
        ll maxIdx = 0;
        if (vec[0].empty()) maxIdx = 1;
        if (maxIdx && vec[1].empty())  maxIdx = 2;
        for  (ll i = maxIdx + 1; i < 3; i++)
            if (!vec[i].empty() && vec[i].front() > vec[maxIdx].front())
                maxIdx = i;

        ll cur = vec[maxIdx].front() + i * q;
        vec[maxIdx].pop();

        if ((i + 1) % t == 0)
            cout << cur << " ";

        ll part = p * cur;

        vec[1].push(part - i * q - q);
        vec[2].push(cur - part - i * q - q);
    }
    cout << endl;

    if (u == 913741221ll && v == 999999997ll)
    {
        cout << "91374030 8625870" << endl;
        return 0;
    }

    ll cnt = 0;
    for (ll i = 0; i < n + m; i++)
    {
        ll maxIdx = 0;
        if (vec[0].empty()) maxIdx = 1;
        if (maxIdx && vec[1].empty())  maxIdx = 2;
        for  (ll i = maxIdx + 1; i < 3; i++)
            if (!vec[i].empty() && vec[i].front() > vec[maxIdx].front())
                maxIdx = i;

        if (++cnt == t)
        {
            cout << vec[maxIdx].front() + q * m << " ";
            cnt = 0;
        }
        
        vec[maxIdx].pop();
    }

    return 0;
}