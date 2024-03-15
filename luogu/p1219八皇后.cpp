#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> row, col, obl1, obl2;
int total = 0;

void dfs(int x = 1)
{
    if (x > n)
    {
        if (total < 3)
        {
            for (int i = 1; i <= n; i++) cout << row[i] << " ";
            cout << endl;
        }
        total++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!col[i] && !obl1[x - i + n] && !obl2[x + i])
        {
            row[x] = i;
            col[i] = 1;
            obl1[x - i + n] = 1;
            obl2[x + i] = 1;
            dfs(x + 1);
            col[i] = 0;
            obl1[x - i + n] = 0;
            obl2[x + i] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    row.resize(n + 1, 0);
    col.resize(n + 1, 0);
    obl1.resize(n * 2 + 1, 0);
    obl2.resize(n * 2 + 1, 0);

    dfs();
    cout << total << endl;

    return 0;
}