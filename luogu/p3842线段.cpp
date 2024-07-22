#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;

    vector<int> left(n + 1);
    vector<int> right(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    for (int i = 1; i <= n; i++) cin >> left[i] >> right[i];

    dp[1][0] = right[1] - 1 + right[1] - left[1];
    dp[1][1] = right[1] - 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + abs(right[i] - left[i - 1]), dp[i - 1][1] + abs(right[i] - right[i - 1])) + right[i] - left[i] + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(left[i] - left[i - 1]), dp[i - 1][1] + abs(left[i] - right[i - 1])) + right[i] - left[i] + 1;
    }

    cout << min(dp[n][0] + n - left[n], dp[n][1] + n - right[n]) << endl;

    return 0;
}