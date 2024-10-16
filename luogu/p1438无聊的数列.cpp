#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> tree, tag;
vector<ll> vec;

void build(ll idx, ll l, ll r)
{
    if (l == r)
    {
        tree[idx] = vec[l] - vec[l - 1];
        return;
    }

    ll mid = l + ((r - l) >> 1);
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

void pushDown(ll idx, ll l, ll r)
{
    ll mid = l + ((r - l) >> 1);

    tag[idx << 1] += tag[idx];
    tree[idx << 1] += (mid - l + 1) * tag[idx];

    tag[idx << 1 | 1] += tag[idx];
    tree[idx << 1 | 1] += (r - mid) * tag[idx];

    tag[idx] = 0;
}

void update(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tree[idx] += (pr - pl + 1) * val;
        tag[idx] += val;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
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

    tree.resize(n << 2);
    tag.resize(n << 2, 0);
    vec.resize(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> vec[i];
    build(1, 1, n);

    ll op, l, r, k, d;
    while (m--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> l >> r >> k >> d;
            update(l, l, 1, 1, n, k - d);
            update(l, r, 1, 1, n, d);
            if (r < n)
                update(r + 1, r + 1, 1, 1, n, -k - d * (r - l));
        }
        else if (op == 2)
        {
            cin >> k;
            cout << query(1, k, 1, 1, n) << endl;
        }
    }

    return 0;
}