#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

vector<vector<int>> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, e, m;
    cin >> n >> e >> m;
    vec.resize(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) vec[i][i] = 0;

    int u, v;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v;
        vec[v][u] = vec[u][v] = 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        cout << vec[u][v] << endl;
    }

    return 0;
}
