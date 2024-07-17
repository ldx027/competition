#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int s[4];
    vector<int> exm[4];
    vector<int> dp;

    for (int i = 0; i < 4; i++) cin >> s[i], exm[i].resize(s[i]);
    for (int i = 0; i < 4; i++) for (int j = 0; j < s[i]; j++) cin >> exm[i][j];

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < s[i]; j++)  sum += exm[i][j];

        dp.clear();
        dp.resize(sum / 2 + 1, 0);

        for (int u = 0; u < s[i]; u++)
        {
            for (int v = sum >> 1; v >= exm[i][u]; v--)
            {
                dp[v] = max(dp[v], dp[v - exm[i][u]] + exm[i][u]);
            }
        }

        ans += (sum - dp[sum >> 1]);
    }

    cout << ans << endl;

    return 0;
}