#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e6 + 10;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
};

int Edge::cnt = 1;
vector<int> Edge::head(maxN, 0);
vector<Edge> edges(maxN << 1);
vector<vector<int>> st(maxN, vector<int>(22, 0));
vector<int> depth(maxN, 0);
vector<int> LOG(maxN);

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

void dfs(int node, int fa)
{
    st[node][0] = fa;
    depth[node] = depth[fa] + 1;

    for (int i = 1; i <= LOG[depth[node]]; i++)
        st[node][i] = st[st[node][i - 1]][i - 1];

    for (int i = Edge::head[node]; i; i = edges[i].next)
        if (edges[i].to != fa)
            dfs(edges[i].to, node);
}

int n, m, s;

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);

    while (depth[u] > depth[v])
        u = st[u][LOG[depth[u] - depth[v]] - 1];

    if (u == v)
        return u;

    for (int k = LOG[depth[u] - 1]; k >= 0; k--)
        if (st[u][k] != st[v][k])
            u = st[u][k], v = st[v][k];

    return st[u][0];
}

int main()
{
    cin >> n >> m >> s;

    LOG[0] = -1;
    for (int i = 1; i <= n + 3; i++)
        LOG[i] = LOG[i << 1] + 1;

    int u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dfs(s, 0);

    while (m--)
    {
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }

    return 0;
}