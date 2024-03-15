#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vec;
int num = 0, precious = 0;
bool flg = 0;

void dfs(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (vec[x][y] == 0)
        return;
    if (vec[x][y] > 1)
        flg = true;
    vec[x][y] = 0;
    dfs(x - 1, y, n, m);
    dfs(x + 1, y, n, m);
    dfs(x, y - 1, n, m);
    dfs(x, y + 1, n, m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    char x;
    vec.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            vec[i][j] = x - '0';
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (vec[i][j])
            {
                dfs(i, j, n, m);
                num++;
                if (flg) precious++;
                flg = 0;
            }
        }

    cout << num << " " << precious << endl;

    return 0;
}