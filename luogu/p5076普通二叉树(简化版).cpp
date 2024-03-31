#include <iostream>
#include <vector>
using namespace std;

#define inf 0x7fffffff

struct Node
{
    int val, cnt, size, left, right;
    Node()
    {
        cnt = 1;
        size = 1;
        left = right = 0;
    }
};

vector<Node> tree;

int cnt = 0;

void insert(int x, int pos = 1)
{

    if (cnt == 0)
    {
        tree[1].val = x;
        cnt++;
        return;
    }

    tree[pos].size++;

    if (tree[pos].val == x)
    {
        tree[pos].cnt++;
    }
    else if (tree[pos].val > x)
    {
        if (tree[pos].left)
        {
            insert(x, tree[pos].left);
        }
        else
        {
            tree[++cnt].val = x;
            tree[cnt].size = tree[cnt].cnt = 1;
            tree[pos].left = cnt;
        }
    }
    else if (tree[pos].val < x)
    {
        if (tree[pos].right)
        {
            insert(x, tree[pos].right);
        }
        else
        {
            tree[++cnt].val = x;
            tree[cnt].size = tree[cnt].cnt = 1;
            tree[pos].right = cnt;
        }
    }
}

int queryFr(int x, int pos = 1, int ans = -inf)
{
    if (tree[pos].val >= x)
    {
        if (tree[x].left)
            return queryFr(x, tree[x].left, ans);
        else
            return ans;
    }
    else
    {
        if (tree[pos].right)
            return queryFr(x, tree[pos].right, tree[pos].val);
        return tree[pos].val < x ? tree[pos].val : ans;
    }
}

int queryNe(int x, int pos = 1, int ans = -inf)
{
    if (tree[pos].val <= x)
    {
        if (tree[x].right)
            return queryNe(x, tree[x].right, ans);
        else
            return ans;
    }
    else
    {
        if (tree[pos].left)
            return queryNe(x, tree[pos].left, tree[pos].val);
        return tree[pos].val > x ? tree[pos].val : ans;
    }
}

int queryRank(int x, int pos = 1)
{
    if (!pos)
        return 0;
    if (x == tree[pos].val)
        return tree[tree[pos].left].size;
    if (x < tree[x].val)
        return queryRank(x, tree[pos].left);
    return queryRank(x, tree[pos].right) + tree[tree[pos].left].size + tree[pos].cnt;
}

int queryVal(int rk, int pos = 1)
{
    if (!pos)
        return inf;
    if (tree[tree[pos].left].size >= rk)
        return queryVal(rk, tree[pos].left);
    if (tree[tree[pos].left].size + tree[pos].cnt >= rk)
        return tree[pos].val;
    return queryVal(rk - tree[tree[pos].left].size - tree[pos].cnt, tree[pos].right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;
    tree.resize(q);
    tree[0].cnt = tree[0].size = 0;

    int op, x;
    for (int i = 0; i < q; i++)
    {
        cin >> op >> x;

        switch (op)
        {
        case 1:
            cout << queryRank(x) + 1 << endl;
            break;
        case 2:
            cout << queryVal(x) << endl;
            break;
        case 3:
            cout << queryFr(x) << endl;
            break;
        case 4:
            cout << queryNe(x) << endl;
            break;
        case 5:
            insert(x);
            break;
        }
    }

    return 0;
}