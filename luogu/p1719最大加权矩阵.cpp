#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;

inline int lowbit(int x) { return x & -x; }

void add(int x, int y, int n)
{
    for (int i = x; i < tree.size(); i += lowbit(i))
    {
        for (int j = y; j < tree[x].size(); j += lowbit(j))
        {
            tree[i][j] += n;
        }
    }
}

int ask(int x, int y)
{
    int rst = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        for (int j = y; j > 0; j -= lowbit(j))
        {
            rst += tree[i][j];
        }
    }
    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    tree.resize(n + 1, vector<int>(n + 1, 0));

    int x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            add(i, j, x);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << ask(i, j) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ans = -1e9;
    for (int a = 0; a <= n; a++)
        for (int b = 0; b <= n; b++)
            for (int c = a + 1; c <= n; c++)
                for (int d = b + 1; d <= n; d++)
                    ans = max(ans, ask(c, d) + ask(a, b) - ask(a, d) - ask(c, b)); 

    cout << ans << endl;

    return 0;
}