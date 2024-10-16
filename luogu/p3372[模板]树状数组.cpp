#include <iostream>
#include <vector>
using namespace std;

#define ll long long 

vector<ll> tree1, tree2;

ll lowbit(ll x) { return x & -x; }

void add1(ll idx, ll val)
{
    while (idx < tree1.size())
    {
        tree1[idx] += val;
        idx += lowbit(idx);
    }
}

void add2(ll idx, ll val)
{
    while (idx < tree2.size())
    {
        tree2[idx] += val;
        idx += lowbit(idx);
    }
}

ll query1(ll idx)
{
    ll rst = 0;
    while (idx)
    {
        rst += tree1[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

ll query2(ll idx)
{
    ll rst = 0;
    while (idx)
    {
        rst += tree2[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    tree1.resize(n + 1, 0);
    tree2.resize(n + 1, 0);

    ll op, x, y, k, old = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;

        add1(i, x - old);
        add2(i, (i - 1) * (x - old));
        old = x;
    }

    while (m--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> x >> y >> k;
            add1(x, k);
            add1(y + 1, -k);
            add2(x, (x - 1) * k);
            add2(y + 1, y * -k);
        }
        else if (op == 2)
        {
            cin >> x >> y;
            cout << y * query1(y) - query2(y) - (x - 1) * query1(x - 1) + query2(x - 1) << endl;
        }
    }

    return 0;
}