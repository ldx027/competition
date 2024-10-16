#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> tree;
vector<bool> tag;

void pushDown(ll idx, ll l, ll r)
{
    if (tag[idx])
    {
        tag[idx] = false;
        ll mid = l + ((r - l) >> 1);

        tag[idx << 1] = !tag[idx << 1];
        tree[idx << 1] = mid - l + 1 - tree[idx << 1];

        tag[idx << 1 | 1] = !tag[idx << 1 | 1];
        tree[idx << 1 | 1] = r - mid - tree[idx << 1 | 1];
    }
}

void update(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
    {
        tag[idx] = !tag[idx];
        tree[idx] = pr - pl + 1 - tree[idx];
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
        update(l, r, idx << 1, pl, mid);
    if (mid < r)
        update(l, r, idx << 1 | 1, mid + 1, pr);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    ll rst = 0;
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

    tree.resize(n << 2, 0);
    tag.resize(n << 2, false);

    ll c, a, b;
    while (m--)
    {
        cin >> c >> a >> b;

        if (c == 0)
            update(a, b, 1, 1, n);
        else if (c == 1)
            cout << query(a, b, 1, 1, n) << endl;
    }

    return 0;
}