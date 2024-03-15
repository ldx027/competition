#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> edge;
vector<bool> vst;

bool flg = false;
int num = 0;
void dfs(int x, int N)
{
    if (flg) cout << " ";
    flg = true;
    cout << x;
    vst[x] = true;
    bool have = false;

    for (int i = 1; i <= N; i++)
    {
        if (edge[x][i] && !vst[i])
        {
            dfs(i, N);
            have = 1;
            num++;
            cout << " " << x;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S;
    cin >> N >> M >> S;
    edge.resize(N + 1, vector<bool>(N + 1, false));
    vst.resize(N + 1, false);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }
    dfs(S, N);

    if (num != N - 1) cout << " 0";

    return 0;
}