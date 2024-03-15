#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &vec, int x, int y, int n, int m)
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (!vec[x][y]) return;
    vec[x][y] = 0;
    dfs(vec, x - 1, y, n, m);
    dfs(vec, x + 1, y, n, m);
    dfs(vec, x, y + 1, n, m);
    dfs(vec, x, y - 1, n, m);
}

vector<vector<int>> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> vec[i][j];

    int rst = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        if (vec[i][j])
        {
            dfs(vec, i, j, n, m);
            rst++;
        }
    }

    cout << rst << endl;

    return 0;
}