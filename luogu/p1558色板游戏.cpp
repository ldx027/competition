#include <iostream>
#include <vector>
using namespace std;

#define ll long long
const int maxN = 1e6 + 10;

vector<ll> tree(maxN, 1 << 1), tag(maxN, 0);

void pushDown(int idx)
{
    if (!tag[idx])
        return;
    
    tree[idx << 1] = 1 << tag[idx];
    tree[idx << 1 | 1] = 1 << tag[idx];
    tag[idx << 1] = tag[idx];
    tag[idx << 1 | 1] = tag[idx];
    tag[idx] = 0;
}

void update(int l, int r, int idx, int pl, int pr, int val)
{
    if (l <= pl && pr <= r)
    {
        tree[idx] = 1 << val;
        tag[idx] = val;
        return;
    }

    pushDown(idx);
    int mid = pl + ((pr - pl) >> 1);
    if (mid >= l) update(l, r, idx << 1, pl, mid, val);
    if (mid < r) update(l, r, idx << 1 | 1, mid + 1, pr, val);
    tree[idx] = tree[idx << 1] | tree[idx << 1 | 1];
}

ll query(int l, int r, int idx, int pl, int pr)
{
    if (l <= pl && pr <= r)
        return tree[idx];
    
    pushDown(idx);

    int rst = 0;
    int mid = pl + ((pr - pl) >> 1);
    if (mid >= l) rst |= query(l, r, idx << 1, pl, mid);
    if (mid < r) rst |= query(l, r, idx << 1 | 1, mid + 1, pr);

    return rst;
}

int count(ll x)
{
    int cnt = 0;
    while (x)
    {
        cnt += (x & 1);
        x >>= 1;
    }
    return cnt;
}

int main()
{
    int l, t, o;
    cin >> l >> t >> o;

    char op;
    int a, b, c;
    while (o--)
    {
        cin >> op >> a >> b;
        if (a > b) swap(a, b);
        
        if (op == 'C')
        {
            cin >> c;
            update(a, b, 1, 1, l, c);
        }
        else
            cout << count(query(a, b, 1, 1, l)) << endl;
    }

    return 0;
}