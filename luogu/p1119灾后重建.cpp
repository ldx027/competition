#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

vector<int> build;
vector<vector<int>> mp;

// 将该步骤单独提取出来
void updata(int k, int n)
{
    build[k] = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
        mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    mp.resize(N, vector<int>(N, inf));
    build.resize(N);
    for (int i = 0; i < N; i++) cin >> build[i];

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        mp[u][v] = mp[v][u] = w;
    }
    for (int i = 0; i < N; i++) mp[i][i] = 0;

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> u >> v >> w;
        if (build[u] - w > 0 || build[v] - w > 0)
        {
            cout << -1 << endl;
            continue;
        }
        for (int j = 0; j < N; j++)
        {
            // if (build[j] - w <= 0)
            if (build[j] - w <= 0 && build[j] != -1)
                updata(j, N);
        }
        if (mp[u][v] == inf)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << mp[u][v] << endl;
        }
    }

    return 0; 
}