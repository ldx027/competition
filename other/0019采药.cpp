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

    int t, m;
    cin >> t >> m;
    w.resize(m + 1);
    v.resize(m + 1);
    dp.resize(t + 1);
    
    for (int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = t; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[t] << endl;

    return 0;
}