#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

#define ll long long
#define inf 0x7f7f7f7f

int main()
{
    int N, L, R;
    cin >> N >> L >> R;

    vector<ll> dp(N + 1, -inf);
    deque<pair<ll, int>> dque;

    ll x;
    for (int i = 0; i <= N; i++)
    {
        cin >> x;
        if (i == 0) dp[0] = x;

        while (!dque.empty() && i - L >= 0 && dp[i - L] >= dque.back().first) dque.pop_back();
        while (!dque.empty() && dque.front().second < i - R) dque.pop_front();
        if (i - L >= 0) dque.push_back({dp[i - L], i - L});
        while (!dque.empty() && dque.front().first == -inf) dque.pop_front();

        if (!dque.empty()) dp[i] = dque.front().first + x;
    }

    for (int i = 0; i <= N; i++) cout << dp[i] << " "; cout << endl;

    ll ans = dp[max(N - R + 1, 0)];
    for (int i = max(N + 1 - R, 1); i <= N; i++) ans = max(ans, dp[i]);

    cout << ans << endl;

    return 0;
}