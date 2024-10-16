#include <iostream>
using namespace std;

#define up(l, r, i) for (int i = l, END##i = r; i <= END##i; ++i)
#define dn(r, l, i) for (int i = r, END##i = l; i >= END##i; --i)

typedef long long i64;

const int INF = 2147483647;
const int MAXN = 1e5 + 3;

int n, t, H[MAXN], F[MAXN];

int main()
{
    while (~scanf("%d", &H[++n]))
        ;
    --n;
    t = 0, memset(F, 0, sizeof(F)), F[0] = INF;
    up(1, n, i)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (F[m] >= H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1; // dp[i]
        if (x > t)
            t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
    t = 0, memset(F, 0, sizeof(F)), F[0] = 0;
    up(1, n, i)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (F[m] < H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t)
            t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
    return 0;
}