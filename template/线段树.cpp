#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

vector<int> vec;
vector<int> tree;

int func(int a, int b)
{
    // return max(a, b);
    return a + b;
}

void build(int l, int r, int p = 1)
{
    if (l == r)
    {
        tree[p] = vec[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    tree[p] = func(tree[p << 1], tree[p << 1 | 1]);

}

int query(int l, int r, int pl, int pr, int p = 1)
{
    if (pl >= l && pr <= r) return tree[p];

    int rst = 0;
    int mid = pl + ((pr - pl) >> 1);
    if (mid >= l) rst = func(rst, query(l, r, pl, mid, p << 1));
    if (mid < r) rst = func(rst, query(l, r, mid + 1, pr, p << 1 | 1));

    return rst;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vec.resize(n);
    tree.resize(4 * n);

    for (int i = 0; i < n; i++) cin >> vec[i];

    build(0, n - 1);

    int l, r;
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        cout << query(l, r, 0, n - 1);
    }

    return 0;
}