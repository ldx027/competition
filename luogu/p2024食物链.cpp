#include <iostream>
#include <vector>
using namespace std;

vector<int> frd;

int findFrd(int u) { return frd[u] ? frd[u] = findFrd(frd[u]) : u; }
bool isFrd(int u, int v) { return findFrd(u) == findFrd(v); }

void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u == v)
        return;
    frd[u] = v;
}

int main()
{
    int n, m;
    cin >> n >> m;

    frd.resize(3 * n + 1, 0);

    int cnt = 0;

    int op, u, v;
    while (m--)
    {
        cin >> op >> u >> v;

        if (u > n || v > n)
        {
            cnt++;
            continue;
        }

        if (op == 1)
        {
            if (isFrd(u, v + n) || isFrd(u + n, v))
                cnt++;
            else
            {
                mkFrd(u, v);
                mkFrd(u + n, v + n);
                mkFrd(u + 2 * n, v + 2 * n);
            }
        }
        else
        {
            if (isFrd(u, v) || isFrd(u + n, v))
                cnt++;
            else
            {
                mkFrd(u, v + n);
                mkFrd(u + n, v + 2 * n);
                mkFrd(u + 2 * n, v);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}