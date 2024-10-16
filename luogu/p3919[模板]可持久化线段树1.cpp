#include <bits/stdc++.h>
using namespace std;

#define res register int
#define ll long long

int cnt, n, a[1000660], m, root[1000660], aaaa;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (isdigit(ch))
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

struct ZXT
{
    int l, r, sum;
} tree[20006660];

inline void build(int &rt, int l, int r)
{
    rt = ++cnt;
    if (l == r)
    {
        tree[rt].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(tree[rt].l, l, mid);
    build(tree[rt].r, mid + 1, r);
}
inline void update(int num, int &rt, int l, int r)
{
    tree[++cnt] = tree[rt];
    rt = cnt;
    int mid = (l + r) / 2;
    if (l == r)
    {
        tree[rt].sum = aaaa;
        return;
    }
    if (num <= mid)
        update(num, tree[rt].l, l, mid);
    else
        update(num, tree[rt].r, mid + 1, r);
}
inline int query(int rt, int l, int r, int kkk)
{
    if (l == r)
        return tree[rt].sum;
    int mid = (l + r) >> 1;
    if (kkk <= mid)
        return query(tree[rt].l, l, mid, kkk);
    else
        return query(tree[rt].r, mid + 1, r, kkk);
}
int main()
{
    n = read();
    m = read();
    for (res i = 1; i <= n; i++)
        a[i] = read();
    build(root[0], 1, n);
    for (res i = 1; i <= m; i++)
    {
        int xxxx = read();
        int yyyy = read();
        if (yyyy == 1)
        {
            int zzzz = read();
            aaaa = read();
            root[i] = root[xxxx];
            update(zzzz, root[i], 1, n);
        }
        else
        {
            int zzzz = read();
            printf("%d\n", query(root[xxxx], 1, n, zzzz));
            root[i] = root[xxxx];
        }
    }
}