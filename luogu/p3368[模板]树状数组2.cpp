#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<int> tree;
vector<int> inn;

inline ll lowbit(ll x) { return x & -x; }

void add(ll idx, ll x)
{
    while (idx < tree.size())
    {
        tree[idx] += x;
        idx += lowbit(idx);
    }
}

ll ask(ll idx)
{
    ll rst = 0;
    
    while (idx > 0)
    {
        rst += tree[idx];
        idx -= lowbit(idx);
    }

    return rst; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    inn.resize(n + 1, 0);
    tree.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> inn[i];

    int x, y, s, cmd;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> x >> y >> s;
            add(x, s);
            add(y + 1, -s);
        }
        else if (cmd == 2)
        {
            cin >> x;
            cout << inn[x] + ask(x) << endl;
        }
    }

    return 0;
}