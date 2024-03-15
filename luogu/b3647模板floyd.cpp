#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(n, 0x3f3f3f3f));
    for (int i = 0; i < n; i++) vec[i][i] = 0;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        vec[u - 1][v - 1] = vec[v - 1][u - 1] = min(w, vec[u - 1][v - 1]);
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
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}