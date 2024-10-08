#include <iostream>
#include <vector>
using namespace std;

#define MAXN 42

int n, m;
vector<int> vec;
vector<int> card(5);
int dp[MAXN][MAXN][MAXN][MAXN] = {0};

int main()
{
    cin >> n >> m;

    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int x;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        card[x]++;
    }

    dp[0][0][0][0] = vec[0];

    for (int a = 0; a <= card[1]; a++)
    {
        for (int b = 0; b <= card[2]; b++)
        {
            for (int c = 0; c <= card[3]; c++)
            {
                for (int d = 0; d <= card[4]; d++)
                {
                    int pos = a + 2 * b + 3 * c + 4 * d;
                    if (a) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + vec[pos]);
                    if (b) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + vec[pos]);
                    if (c) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + vec[pos]);
                    if (d) dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + vec[pos]);
                }
            }
        }
    }

    cout << dp[card[1]][card[2]][card[3]][card[4]] << endl;

    return 0;
}
