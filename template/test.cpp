#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> u;
vector<int> v;

int main()
{
    int n, w;
    cin >> n >> w;

    dp.resize(w + 1, 0);
    u.resize(n + 1);
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> u[i] >> v[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = w; j >= u[i]; j--)
        {
            dp[j - u[i]] = max(dp[j - u[i]], dp[j] + v[i]);
        }
    }

    cout << dp[0] << endl;

    return 0;
}
