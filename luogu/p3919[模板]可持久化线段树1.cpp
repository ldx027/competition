#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
struct Node
{
    int l = 0, r = 0, val;
};
vector<Node> tree;
vector<int> root;
vector<int> vec;

int read()
{
    int sig = 1, num = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            sig = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        num *= 10;
        num += c - '0';
        c = getchar();
    }

    return sig * num;
}

int build(int l, int r)
{
    int node = cnt++;

    if (l == r)
    {
        tree[node].val = vec[l];
        return node;
    }

    int mid = l + ((r - l) >> 1);
    tree[node].l = build(l, mid);
    tree[node].r = build(mid + 1, r);

    return node;
}

int update(int prev, int l, int r, int idx, int val)
{
    int node = cnt++;
    tree[node] = tree[prev];

    if (l == r)
    {
        tree[node].val = val;
        return node;
    }

    int mid = l + ((r - l) >> 1);
    if (idx <= mid)
        tree[node].l = update(tree[node].l, l, mid, idx, val);
    else if (idx > mid)
        tree[node].r = update(tree[node].r, mid + 1, r, idx, val);
    
    // tree[node].val = tree[tree[node].l].val + tree[tree[node].r].val;

    return node;
}

int query(int node, int l, int r, int idx)
{
    if (l == r)
        return tree[node].val;
    
    int mid = l + ((r - l) >> 1);
    if (idx <= mid)
        return query(tree[node].l, l, mid, idx);
    else
        return query(tree[node].r, mid + 1, r, idx);
}

int main()
{
    int n, m;
    n = read(), m = read();

    tree.resize((n + m) << 4);
    vec.resize(n + 1);
    root.resize(m + 1);

    for (int i = 1; i <= n; i++)
        vec[i] = read();
    root[0] = build(1, n); 
    
    int v, op, idx, val;
    for (int i = 1; i <= m; i++)
    {
        v = read(), op = read(), idx = read();
        if (op == 1)
        {
            val = read();
            root[i] = update(root[v], 1, n, idx, val);
        }
        else
        {
            cout << query(root[v], 1, n, idx) << endl;
            root[i] = root[v];
        }
    }

    return 0;
}
