#include <iostream>
#include <vector>
using namespace std;

#define mod (int(1e6+7))

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> vec(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec[i];

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int u = 1; u <= min(j, vec[i]); u++)
            {
                dp[j] = (dp[j] + dp[j - u]) % mod;
            }
        }
    }

    cout << dp[m];

    return 0;
}