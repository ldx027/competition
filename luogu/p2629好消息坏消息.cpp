#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

#define ll long long
#define wtf std::cout<<"wtf"<<std::endl

vector<ll> vec;

int lowbit(ll x) { return x & -x; }

void add(int idx, ll x)
{
    while (idx < vec.size())
    {
        vec[idx] += x;
        idx += lowbit(idx);
    }
}

ll sum(int idx)
{
    ll rst = 0;   
    while (idx > 0)
    {
        rst += vec[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    int n;
    cin >> n;

    vec.resize(2 * n + 1);

    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        add(i, x);
        add(i + n, x);
    }

    int ans = 0;
    deque<pair<int, int>> que;

    for (int i = 1; i <= 2 * n; i++)
    {
        ll cur = sum(i);

        while (!que.empty() && cur <= que.back().first) que.pop_back();
        while (!que.empty() && i - que.front().second >= n) que.pop_front();
        que.push_back({cur, i});

        if (i > n)
        {
            if (que.front().first - sum(i - n) >= 0) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}