#include <iostream>
#include <vector>
using namespace std;

#define inf 1145141919810
#define ll long long

struct Node
{
    ll val, sum, set;
    bool cover = false;
};

vector<ll> vec;
vector<Node> tree;

void build(ll idx, ll l, ll r)
{
    tree[idx].sum = tree[idx].set = tree[idx].cover = 0;
    if (l == r)
    {
        tree[idx].val = vec[l];
        return;
    }

    ll mid = l + ((r - l) >> 1);
    build(idx << 1, l, mid);
    build(idx << 1 | 1, mid + 1, r);
    tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
}

void pushDown(ll idx, ll l, ll r)
{
    if (tree[idx].cover)
    {
        tree[idx].cover = false;
        tree[idx << 1].val = tree[idx].val;
        tree[idx << 1].sum = 0;
        tree[idx << 1].set = tree[idx].set;
        tree[idx << 1].cover = true;
        tree[idx << 1 | 1].val = tree[idx].val;
        tree[idx << 1 | 1].sum = 0;
        tree[idx << 1 | 1].set = tree[idx].set;
        tree[idx << 1 | 1].cover = true;
    }

    tree[idx << 1].val += tree[idx].sum;
    tree[idx << 1].sum += tree[idx].sum;
    tree[idx << 1 | 1].val += tree[idx].sum;
    tree[idx << 1 | 1].sum += tree[idx].sum;
    tree[idx].sum = 0;
}

void set(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tree[idx].val = val;
        tree[idx].sum = 0;
        tree[idx].set = val;
        tree[idx].cover = true;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) set(l, r, idx << 1, pl, mid, val);
    if (mid < r) set(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
}

void add(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    if (l <= pl && pr <= r)
    {
        tree[idx].sum += val;
        tree[idx].val += val;
        return;
    }

    pushDown(idx, pl, pr);
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) add(l, r, idx << 1, pl, mid, val);
    if (mid < r) add(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx].val = max(tree[idx << 1].val, tree[idx << 1 | 1].val);
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx].val;

    pushDown(idx, pl, pr);    
    ll rst = -inf;
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) rst = max(rst, query(l, r, idx << 1, pl, mid));
    if (mid < r) rst = max(rst, query(l, r, idx << 1 | 1, mid + 1, pr));

    return rst;
}

int main()
{
    ll n, q;
    cin >> n >> q;

    vec.resize(n + 1);
    tree.resize(n << 2);

    for (ll i = 1; i <= n; i++)
        cin >> vec[i];
    build(1, 1, n);

    ll op, l, r, x;
    while (q--)
    {
        cin >> op >> l >> r;
        if (op == 1)
        {
            cin >> x;
            set(l, r, 1, 1, n, x);
        }
        else if (op == 2)
        {
            cin >> x;
            add(l, r, 1, 1, n, x);
        }
        else if (op == 3)
        {
            cout << query(l, r, 1, 1, n) << endl;
        }
    }

    return 0;
}