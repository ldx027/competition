#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int main()
{
    int T, M;
    cin >> T >> M;

    dp.resize(T + 1, 0);

    int u, v;

    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        for (int j = T; j >= u; j--)
        {
            dp[j] = max(dp[j], dp[j - u] + v);
        }
    }

    cout << dp[T] << endl;

    return 0;
}