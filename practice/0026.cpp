#include <iostream>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    ll n, m, x;
    while (T--)
    {
        cin >> n >> m >> x;
        vector<vector<char>> vec(n, vector<char>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> vec[i][j];

        vector<vector<pair<ll, ll>>> dp(n + 1, vector<pair<ll, ll>>(m + 1, {0, x}));
        dp[n - 1][m - 1] = {0, x};
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (vec[i][j] == '1')
                    dp[i][j].first++;

                else if (vec[i][j] == '?' && dp[i][j].second > 0)
                {
                    dp[i][j].first++;
                    dp[i][j].second--;
                }

                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            }
        }

        cout << dp[n - 1][m - 1].first << endl;
    }

    return 0;
}
