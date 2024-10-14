#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> vec, tree, tag;

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
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void addTag(ll idx, ll l, ll r, ll val)
{
    tag[idx] += val;
    tree[idx] += (r - l + 1) * val;
}

void pushDown(ll idx, ll l, ll r)
{
    if (!tag[idx]) return;
    ll mid = l + ((r - l) >> 1);
    addTag(idx << 1, l, mid, tag[idx]);
    addTag(idx << 1 | 1, mid + 1, r, tag[idx]);
    tag[idx] = 0;
}

void update(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        addTag(idx, pl, pr, val);
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (l <= mid)
        update(l, r, idx << 1, pl, mid, val);
    if (mid < r)
        update(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];

    pushDown(idx, pl, pr);
    ll rst = 0;
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
        rst += query(l, r, idx << 1, pl, mid);
    if (mid < r)
        rst += query(l, r, idx << 1 | 1, mid + 1, pr);
    return rst;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vec.resize(n + 1, 0);
    tree.resize(n << 2, 0);
    tag.resize(n << 2, 0);

    for (ll i = 1; i <= n; i++)
        cin >> vec[i];
    build(1, 1, n);

    ll op, x, y, k;
    while (m--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> x >> y >> k;
            update(x, y, 1, 1, n, k);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << query(x, y, 1, 1, n) << endl;
        }
    }

    return 0;
}