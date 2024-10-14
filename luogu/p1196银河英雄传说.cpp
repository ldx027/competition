#include <iostream>
#include <vector>
using namespace std;

const int n = 3e5;

vector<int> frd(n + 1, 0);
vector<int> no(n + 1, 0);
vector<int> len(n + 1, 1);

int findFrd(int u)
{
    if (!frd[u]) return u;
    int fu = findFrd(frd[u]);
    no[u] += no[frd[u]];
    return frd[u] = fu;
}

int main()
{
    int T;
    cin >> T;

    char op;
    int u, v;
    while (T--)
    {
        cin >> op >> u >> v;

        int fu = findFrd(u);
        int fv = findFrd(v);

        if (op == 'M')
        {
            no[fu] += len[fv];
            len[fv] += len[fu];
            frd[fu] = fv;
        }
        else if (op == 'C')
        {
            if (fu == fv)
                cout << abs(no[u] - no[v]) - 1 << endl;
            else
                cout << -1 << endl;
        }
    }

    return 0;
}