#include <iostream>
#include <vector>
using namespace std;

vector<int> w;
vector<int> v;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, c;
    cin >> n >> c;
    w.resize(n + 1, 0);
    v.resize(n + 1, 0);
    dp.resize(c + 1, 0);
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = c; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[c] << endl;

    return 0;
}