#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll n, c;
vector<ll> vec;
vector<ll> sum;

ll lowbit(ll x) { return x & -x; }

void add(ll idx, ll x)
{
    while (idx < sum.size())
    {
        sum[idx] += x;
        idx += lowbit(idx);
    }
}

ll query(ll idx)
{
    ll rst = 0;
    while (idx)
    {
        rst += sum[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

ll ans = 0;

void dfs(ll idx, ll cur = 0)
{
    if (cur > c) return;
    ans = max(ans, cur);
    if (idx <= 0) return;

    if (query(idx) + cur <= c)
    {
        ans = max(ans, query(idx) + cur);
        return;
    }

    dfs(idx - 1, cur + vec[idx]);
    dfs(idx - 1, cur);
}

int main()
{
    cin >> n >> c;
    
    vec.resize(n + 1);
    sum.resize(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> vec[i];
        add(i, vec[i]);
    }    

    dfs(n);

    cout << ans << endl;

    return 0;
}