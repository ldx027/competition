#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n, m, s;
vector<ll> w, v;
vector<ll> l, r;

int main()
{
    cin >> n >> m >> s;

    w.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i<= n; i++)
        cin >> w[i] >> v[i];

    l.resize(m);
    r.resize(m);
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i];
}