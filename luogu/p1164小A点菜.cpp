#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<int> w;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    dp.resize(N + 1, vector<int>(M + 1, 0));
    w.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> w[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            if (j == w[i])
                dp[i][j] = dp[i - 1][j] + 1;
            else if (j > w[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - w[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[N][M] << endl;

    return 0;
}