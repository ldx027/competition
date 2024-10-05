#include <iostream>
using namespace std;

#define MAXN 100010

int n, m;
int dp[MAXN][20];
int LOG2[MAXN];

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

int main()
{
    n = read();
    m = read();

    LOG2[0] = -1;
    for (int i = 1; i <= n; i++)
        LOG2[i] = LOG2[i >> 1] + 1;

    for (int i = 1; i <= n; i++)
        dp[i][0] = read();

    for (register int i = 1; i <= LOG2[n]; i++)
        for (register int j = 1; (j + (1 << (i - 1))) <= n; j++)
            dp[j][i] = max(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]);

    int l, r, k;
    for (register int i = 0; i < m; i++)
    {
        l = read();
        r = read();
        k = LOG2[r - l + 1];
        cout << max(dp[l][k], dp[r - (1 << k) + 1][k]) << endl;
    }

    return 0;
}