#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> dp;
vector<int> x, y, v;

int main()
{
    cin >> n >> m;

    x.resize(n);
    y.resize(n);
    v.resize(n);

    int Maxx = 0, Maxy = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> v[i];
        x[i]++, y[i]++;
        Maxx = max(Maxx, x[i]);
        Maxy = max(Maxy, y[i]);
    }

    dp.resize(Maxx + 2 + m, vector<int>(Maxy + 2 + m, 0));

    for (int i = 0; i < n; i++)
    {
        dp[x[i]][y[i]] += v[i];
        dp[x[i] + m][y[i]] -= v[i];
        dp[x[i]][y[i] + m] -= v[i];
        dp[x[i] + m][y[i] + m] += v[i];
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)
    //         printf("%2d ", dp[i][j]);
    //     cout << endl;
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 1; i < Maxx + m + 2; i++)
    {
        for (int j = 1; j < Maxy + m + 2; j++)
        {
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            ans = max(ans, dp[i][j]);
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)
    //         printf("%2d ", dp[i][j]);
    //     cout << endl;
    // }

    cout << ans << endl;

    return 0;
}