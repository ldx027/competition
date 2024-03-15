#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

vector<int> cj;
int canBe(int x, int city, int t)
{
    return (cj[city] - t <= 0 ? x : inf);
}

int lastT = -inf;
void floyd(vector<vector<int>> &vec, int x, int y, int t, int N)
{
    // cout << "ans";
    if (cj[x] - t > 0 || cj[y] - t > 0)
    {
        cout << -1 << endl;
        return;
    }
    for (int k = 0; k < N; k++)
    {
        if (cj[k] - t > 0) continue;
        for (int i = 0; i < N; i++)
        {
            if (cj[i] - t > 0) continue;
            for (int j = 0; j < N; j++)
            {
                if (cj[j] - t > 0) continue;
                vec[i][j] = min(vec[i][j], vec[i][k] + vec[k][j]);
            }
        }
    }
    cout << (vec[x][y] == inf ? -1 : vec[x][y]) << endl;
    lastT = t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int N, M;
    cin >> N >> M;
    cj.resize(N);
    for (int i = 0; i < N; i++) cin >> cj[i];

    vector<vector<int>> vec(N, vector<int>(N, inf));
    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        vec[u][v] = w;
        vec[v][u] = w;
    }

    int Q;
    cin >> Q;
    int x, y, t;
    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y >> t;
        floyd(vec, x, y, t, N);
    }

    return 0;
}