#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll int

struct Soldier
{
    ll id, l, r; 
};

bool cmp(Soldier a, Soldier b) { return a.l < b.l; }

ll n, m;
vector<Soldier> vec;
vector<vector<ll>> go;
vector<int> ans;

void pre()
{
    for (ll i = 1; i <= 2 * n; i++)
    {
        ll to = i;
        while (to <= 2 * n && vec[to].l <= vec[i].r)
            to++;
        go[i][0] = to - 1;
    }

    for (ll i = 1; i < 20; i++)
        for (ll j = 1; j <= 2 * n; j++)
            go[j][i] = go[go[j][i - 1]][i - 1];
}

void search(ll k)
{
    ll lmt = vec[k].l + m;
    ll val = 2;
    ll p = k;

    for (ll i = 19; i >= 0; i--)
    {
        if (go[k][i] != 0 && vec[go[k][i]].r < lmt)
        {
            val += (1 << i);
            k = go[k][i];
        }
    }

    ans[vec[p].id] = val;
}

int main()
{
    cin >> n >> m;
    
    vec.resize(2 * n + 1);
    go.resize(2 * n + 1, vector<ll>(21, 0));
    ans.resize(n + 1);

    for (ll i = 1; i <= n; i++)
    {
        vec[i].id = i;
        cin >> vec[i].l >> vec[i].r;
        if (vec[i].r < vec[i].l)
            vec[i].r += m;
    }

    sort(vec.begin() + 1, vec.begin() + n + 1, cmp);

    for (ll i = 1; i <= n; i++)
    {
        vec[i + n].id = vec[i].id;
        vec[i + n].l = vec[i].l + m;
        vec[i + n].r = vec[i].r + m;
    }

    pre();

    for (int i = 1; i <= n; i++)
        search(i);
    
    for (int i = 1; i <= n; i++)
        cout << ans[i]  << " ";

    return 0;
}