#include <iostream>
#include <vector>
using namespace std;

int findFrd(vector<int> &frd, int u)
{
    return frd[u] == 0 ? u : frd[u] = findFrd(frd, frd[u]);
}

void mkFrd(vector<int> &frd, int u, int v)
{
    u = findFrd (frd, u);
    v = findFrd (frd, v);
    if (u == v) return;
    frd[u] = v;
}

bool isFrd(vector<int> &frd, int u, int v)
{
    u = findFrd(frd, u);
    v = findFrd(frd, v);
    return u == v;
}

int main()
{
    int n, m;
    while (1)
    {
        cin >> n;
        if (n == 0) break;
        cin >> m;

        int u, v;
        vector<int> frd(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            mkFrd(frd, u, v);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!isFrd(frd, i, j))
                {
                    ++ans;
                    mkFrd(frd, i, j);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}