#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> vec, tree;

void build(ll idx, ll l, ll r)
{
    if (l == r)
    {
        tree[idx] = vec[l];
        return;
    }

    ll mid = l + ((r - l) >> 1);
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    tree[idx] = min(tree[idx << 1], tree[idx << 1 | 1]);
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];
    
    ll rst = 0x7f7f7f7f;
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) rst = min(rst, query(l, r, idx << 1, pl, mid));
    if (mid < r) rst = min(rst, query(l, r, idx << 1 | 1, mid + 1, pr));
    return rst;
}

int main()
{
    ll m, n;
    cin >> m >> n;

    vec.resize(m + 1);
    tree.resize(m << 2);

    for (ll i = 1; i <= m; i++)
        cin >> vec[i];
    build(1, 1, m);

    ll x, y;
    while (n--)
    {
        cin >> x >> y;
        cout << query(x, y, 1, 1, m) << " ";
    }

    return 0;
}