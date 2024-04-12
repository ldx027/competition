#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;

int lowbit(int x) { return x & -x; }

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

    return 0;
}