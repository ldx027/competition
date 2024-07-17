#include <iostream>
#include <vector>
using namespace std;

vector<bool> dp;
vector<int> u;

int main()
{
    int V, n;
    cin >> V >> n;

    dp.resize(V + 1, false);
    dp[V] = true;
    u.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> u[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = u[i]; j <= V; j++)
        {
            dp[j - u[i]] = dp[j - u[i]] || dp[j];
        }
    }

    for (int i = 0; i <= V; i++)
    {
        if (dp[i])
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}