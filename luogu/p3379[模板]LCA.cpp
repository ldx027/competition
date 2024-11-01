#include <iostream>
#include <vector>
using namespace std;

const int maxN = 5e5 + 10;

struct Edge
{
    static int cnt;
    static int head[maxN];
    int to;
    int next;
};

int Edge::cnt = 1;
int Edge::head[maxN];
Edge edges[maxN];
int depth[maxN];
int fa[maxN][20];
int LOG[maxN];

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

void dfs(int cur, int prev)
{
    fa[cur][0] = prev;
    depth[cur] = depth[prev] + 1;
    for (int i = 1; i < 20; i++)
        fa[cur][i] = fa[fa[cur][i - 1]][i - 1];
    for (int i = Edge::head[cur]; i; i = edges[i].next)
        if (edges[i].to != prev)
            dfs(edges[i].to, cur);
}

int LCA(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    
    cout << fa[v][0] << endl;
    exit(0);
    while (depth[u] != depth[v])
        u = fa[u][LOG[depth[u] - depth[v]]];

    cout << u << " " << v << endl;
    
    if (u == v)
        return u;
    
    for (int i = 19; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];

    return fa[u][0];
}

int main()
{
    int n, m, s;
    cin >> n >> m >> s;

    depth[0] = 0;
    LOG[0] = -1;
    for (int i = 1; i <= n; i++)
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