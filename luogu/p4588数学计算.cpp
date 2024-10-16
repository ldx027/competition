#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll mod;
vector<ll> tree;

void update(ll pos, ll idx, ll l, ll r, ll val)
{
    if (l == r)
    {
        tree[idx] = val;
        return;
    }

    ll mid = l + ((r - l) >> 1);
    if (mid >= pos) update(pos, idx << 1, l, mid, val);
    if (mid < pos) update(pos, idx << 1 | 1, mid + 1, r, val);
    tree[idx] = tree[idx << 1] * tree[idx << 1 | 1] % mod;
}

ll query(ll l, ll r, ll idx, ll pl, ll pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];
    
    ll ans = 1;
    ll mid = pl + ((pr - pl) >> 1);
    if (mid >= l) ans = (ans * query(l, r, idx << 1, pl, mid)) % mod; 
    if (mid < r) ans = (ans * query(l, r, idx << 1 | 1, mid + 1, pr)) % mod;

    return ans;
}

int main()
{
    ll T;
    cin >> T;

    while (T--)
    {
        ll q;
        cin >> q >> mod;

        tree.clear();
        tree.resize(q << 2, 1);

        ll op, m;
        for (ll i = 1; i <= q; i++)
        {
            cin >> op >> m;

            if (op == 1)
                update(i, 1, 1, q, m);
            else
                update(m, 1, 1, q, 1);
            
            cout << query(1, i, 1, 1, q) << endl;
        }
    }

    return 0;
}