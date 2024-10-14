#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> vec, tree;
vector<vector<ll>> tag;

ll mod;

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
    tree[idx] %= mod;

    tag[idx][0] = 0;
    tag[idx][1] = 1;
}

void pushDown(ll idx, ll l, ll r)
{
    ll mid = l + ((r - l) >> 1);
    tree[idx << 1] *= tag[idx][1];
    tree[idx << 1] += tag[idx][0] * (mid - l + 1);
    tree[idx << 1] %= mod;
    tree[idx << 1 | 1] *= tag[idx][1];
    tree[idx << 1 | 1] += tag[idx][0] * (r - mid);
    tree[idx << 1 | 1] %= mod;

    tag[idx << 1][1] *= tag[idx][1];
    tag[idx << 1][0] *= tag[idx][1];
    tag[idx << 1][0] += tag[idx][0];
    tag[idx << 1 | 1][1] *= tag[idx][1];
    tag[idx << 1 | 1][0] *= tag[idx][1];
    tag[idx << 1 | 1][0] += tag[idx][0];

    tag[idx << 1][0] %= mod;
    tag[idx << 1][1] %= mod;
    tag[idx << 1 | 1][0] %= mod;
    tag[idx << 1 | 1][1] %= mod;

    tag[idx][1] = 1;
    tag[idx][0] = 0;
}

void add(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tag[idx][0] += val;
        tag[idx][0] %= mod;
        tree[idx] += (pr - pl + 1) * val;
        tree[idx] %= mod;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
        add(l, r, idx << 1, pl, mid, val);
    if (mid < r)
        add(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    tree[idx] %= mod;
}

void mul(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tag[idx][1] *= val;
        tag[idx][1] %= mod;
        tag[idx][0] *= val;
        tag[idx][0] %= mod;
        tree[idx] *= val;
        tree[idx] %= mod;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l)
        mul(l, r, idx << 1, pl, mid, val);
    if (mid < r)
        mul(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
    tree[idx] %= mod;
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
    rst %= mod;
    return rst;
}

void show(int n)
{
    for (int i = 1; i <= n; i++)
        cout << query(i, i, 1, 1, n) << " ";
    cout << endl;
}

int main()
{
    ll n, q;
    cin >> n >> q >> mod;

    vec.resize(n + 1);
    tree.resize(n << 2);
    tag.resize(n << 2, vector<ll>({0, 1}));

    for (int i = 1; i <= n; i++)
        cin >> vec[i];

    build(1, 1, n);

    ll op, x, y, k;
    while (q--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> x >> y >> k;
            mul(x, y, 1, 1, n, k);
            break;
        
        case 2:
            cin >> x >> y >> k;
            add(x, y, 1, 1, n, k);
            break;
        
        case 3:
            cin >> x >> y;
            cout << query(x, y, 1, 1, n) << endl;
            break;
        }
        // show(n);
    }

    return 0;
}