#include <iostream>
#include <vector>
using namespace std;

#define JD 16 
const int maxN = 1e5 + 7;

int LOG[maxN];
int st[maxN][JD + 1];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    int n, m;
    n = read(), m = read();

    LOG[0] = -1;
    for (register int i = 1; i <= n + 1; i++)
        LOG[i] = LOG[i >> 1] + 1;

    for (register int i = 1; i <= n; i++)
        st[i][0] = read();

    for (register int i = 1; i <= JD; i++)
        for (register int j = 1; j + (1 << (i - 1)) <= n; j++)
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);

    int l, r;
    while (m--)
    {
        l = read(), r = read();

        int k = LOG[r - l + 1];
        printf("%d\n", max(st[l][k], st[r - (1 << k) + 1][k]));
    }

    return 0;
}