#include <iostream>
#include <vector>
#include <deque>
using namespace std;

typedef long long ll;

vector<ll> sum;

ll lowbit(ll x) { return x & -x; }

void add(ll idx, ll val)
{
    while (idx < sum.size())
    {
        sum[idx] += val;
        idx += lowbit(idx);
    }
}

ll ask(ll idx)
{
    ll rst = 0;
    while (idx > 0)
    {
        rst += sum[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    ll n, m, x;
    cin >> n >> m;

    sum.resize(n + 1, 0);

    for (ll i = 1; i <= n; i++)
    {
        cin >> x;
        add(i, x);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << ask(i) << " ";
    // }
    // cout << endl;

    deque<ll> que;
    que.push_back(0);

    ll ans = -0x3f3f3f3f;
    for (ll i = 1; i <= n; i++)
    {
        while (!que.empty() && que.front() + m < i) que.pop_front();
        ans = max(ans, ask(i) - ask(que.front()));
        // cout << i << " " << ask(i) << " " << ask(que.front()) << endl;
        while (!que.empty() && ask(que.back()) >= ask(i)) que.pop_back();
        que.push_back(i);
    }

    cout << ans << endl;

    return 0;
}