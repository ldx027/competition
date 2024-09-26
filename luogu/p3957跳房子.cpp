#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

#define ll long long
#define inf 0x7f7f7f7f

ll n, d, k;
vector<ll> dis;
vector<ll> score;

ll bin(ll l, ll r)
{
    if (l > r)
        return inf;

    ll mid = l + ((r - l) >> 1);
    // cout << "mid" << mid << endl;

    vector<ll> dp(n, -inf);
    deque<pair<ll, ll>> que;
    ll cur = 0;

    ll Max = -inf;
    for (ll i = 0; i < n; i++)
    {
        if (dis[i] >= d - mid && dis[i] <= mid + d)
            dp[i] = score[i];

        /* 找max（0, i - d -g）到 min(i - 1, g - d + i)项最大值
        for (int j = 0; j < i; j++)
            if (dis[j] >= dis[i] - d - mid && dis[j] <= min(dis[i] - 1, mid - d + dis[i]))
                dp[i] = max(dp[i], dp[j] + score[i]);
        */
        while (dis[cur] <= min(dis[i] - 1, dis[i] - d + mid))
        {
            while (!que.empty() && que.back().second <= dp[cur])
                que.pop_back();
            que.push_back({dis[cur], dp[cur++]});
        }
        while (!que.empty() && que.front().first < dis[i] - d - mid)
            que.pop_front();

        if (!que.empty())
            dp[i] = max(dp[i], que.front().second + score[i]);
        Max = max(Max, dp[i]);
        if (Max >= k)
            break;
    }
    // for (int j = 0; j < n; j++)
    //     cout << dp[j] << " ";
    // cout << endl;

    if (Max >= k)
        return min(bin(l, mid - 1), mid);
    else
        return bin(mid + 1, r);
}

int main()
{
    cin >> n >> d >> k;
    dis.resize(n);
    score.resize(n);

    ll total = 0;
    for (int i = 0; i < n; i++)
        cin >> dis[i] >> score[i], total += max(score[i], (ll)0);

    // 不足特判
    if (total < k)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << bin(0, dis[n - 1]);

    return 0;
}