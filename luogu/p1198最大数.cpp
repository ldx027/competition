#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define inf 0x3f3f3f3f
#define maxN 200007

ll mod;
vector<ll> tree(maxN << 2 + 1, -inf);

void add(ll l, ll r, ll idx, ll pl, ll pr, ll val)
{
    // cout << idx << " " << pl << " " << pr << endl;
    if (l <= pl && pr <= r)
    {
        tree[idx] = val % mod;
        return;
    }
    
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) add(l, r, idx << 1, pl, mid, val);
    if (mid < r) add(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = max(tree[idx << 1], tree[idx << 1 | 1]) % mod;
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];
    
    ll rst = -inf;
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) rst = max(rst, query(l, r, idx << 1, pl, mid));
    if (mid < r) rst = max(rst, query(l, r, idx << 1 | 1, mid + 1, pr));
    return rst;
}

int main()
{
    ll m;
    cin >> m >> mod;

    ll cur = 1, t = 0;
    char op;
    ll x;
    while (m--)
    {
        cin >> op >> x;
        if (op == 'A')
        {
            add(cur, cur, 1, 1, maxN, x + t);
            cur++;
        }
        else
        {
            cout << (t = query(max(cur - x, 1ll), cur, 1, 1, maxN)) << endl;
        }
    }

    return 0;
}