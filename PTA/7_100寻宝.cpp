#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vec.resize(m + 1, vector<int>(n + 1, 0));
    dp.resize(n + 1, 0);
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
    {
        cin >> vec[i][j];
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
    {
        dp[j] = vec[i][j] + max(dp[j], dp[j - 1]);
    }
    cout << dp[n] << endl;

    return 0;
}