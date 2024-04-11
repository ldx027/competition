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

    int n, m;
    cin >> n >> m;

    w.resize(n);
    v.resize(n);
    dp.resize(m + 1, 0);

    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[m] << endl;

    return 0;
}