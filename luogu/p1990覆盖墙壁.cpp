#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(2, 0));

    dp[1][0] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;

    for (int i = 3; i <= N; i++)
    {
        dp[i][1] = (dp[i - 2][0] + dp[i - 1][1]) % 10000;
        dp[i][0] = (dp[i - 1][0] + 2 * dp[i - 1][1] + dp[i - 2][0]) % 10000;
    }

    cout << dp[N][0] << endl;

    return 0;
}