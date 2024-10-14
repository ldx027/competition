#include <iostream>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

#define ll long long
#define inf 0x7f7f7f7f
// #define debug

ll n, d, k;
vector<ll> dis, score;

bool check(ll mid)
{
    deque<pair<ll, ll>> que;
    vector<ll> dp(n, -inf);

    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        while (cur < i && dis[cur] <= min(dis[i] - d + mid, dis[i] - 1))
        {
            if (dp[cur] == -inf)
            {
                cur++;
                continue;
            }

            while (!que.empty() && que.back().first <= dp[cur])
                que.pop_back();
            que.push_back({dp[cur], cur});
            cur++;
        }
        while (!que.empty() && dis[que.front().second] < dis[i] - d - mid)
            que.pop_front();

        if (d - mid <= dis[i] && dis[i] <= d + mid)
            dp[i] = score[i];
        if (!que.empty())
            dp[i] = max(dp[i], que.front().first + score[i]);

#ifdef debug
        cout << i << " " << dp[i] << endl;
#endif
        if (dp[i] >= k)
            return true;
    }

    return false;
}

int main()
{
    cin >> n >> d >> k;

    dis.resize(n);
    score.resize(n);

    for (ll i = 0; i < n; i++)
        cin >> dis[i] >> score[i];

    // cout << "over" << endl;

    ll ans = -1;
    ll l = 0, r = dis[n - 1];

    while (l <= r)
    {
        ll mid = l + ((r - l) >> 1);
#ifdef debug
        cout << l << " " << r << " " << mid << endl;
#endif
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;

    return 0;
}