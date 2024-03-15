#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<bool>> edge;
vector<bool> vst;
queue<int> que;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;
    edge.resize(n + 1, vector<bool>(n + 1, false));
    vst.resize(n + 1, false);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edge[u][v] = true;
        edge[v][u] = true;
    }

    que.push(s);
    int num = 0;
    bool have = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        if (vst[cur]) continue;
        num++;
        vst[cur] = true;
        if (have) cout << " ";
        cout << cur;
        have = 1;
        for (int i = 1; i <= n; i++)
        {
            if (edge[cur][i] && !vst[i]) que.push(i);
        }
    }

    if (num != n) cout << " 0";

    return 0;
}