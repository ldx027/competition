#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

void floyd(vector<vector<int>> &vec)
{
    int N = vec.size();

    for (int k = 1; k < N; k++)
    {
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j < N; j++)
            {
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> vec(N + 1, vector<int>(N + 1, inf));

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        vec[u][v] = vec[v][u] = w;
    }

    for (int i = 1; i <= N; i++) vec[i][i] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}