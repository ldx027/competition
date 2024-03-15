#include <iostream>
#include <vector>
using namespace std;

vector<int> waste;
vector<int> value;
vector<vector<int>> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, M;
    cin >> T >> M;
    waste.resize(M + 1);
    value.resize(M + 1);
    dp.resize(M + 1, vector<int>(T + 1, 0));
    for (int i = 1; i <= M; i++)
        cin >> waste[i] >> value[i];

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= waste[i])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - waste[i]] + value[i]);
            }
        }
    }

    cout << dp[M][T] << endl;

    return 0;
}