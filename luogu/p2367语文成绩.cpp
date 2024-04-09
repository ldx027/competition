#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
vector<int> inn;

inline int lowbit(int x) { return x & -x; }

void add(int idx, int x)
{
    while (idx < tree.size())
    {
        tree[idx] += x;
        idx += lowbit(idx);
    }
}

int ask(int idx)
{
    int rst = 0;
    while (idx > 0)
    {
        rst += tree[idx];
        idx -= lowbit(idx);
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, p;
    cin >> n >> p;

    inn.resize(n + 1, 0);
    tree.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> inn[i];
    }

    int x, y, s;
    for (int i = 0; i < p; i++)
    {
        cin >> x >> y >> s;
        add(x, s);
        add(y + 1, -s);
    }

    int Min = inn[1] + ask(1);
    for (int i = 2; i <= n; i++)
    {
        Min = min(Min, inn[i] + ask(i));
    }

    cout << Min << endl;
}