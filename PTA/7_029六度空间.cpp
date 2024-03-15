#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
};
int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

int dfs(int x, int fr = 0, int dep = 6)
{
    if (dep < 0) return 0;
    int rst = 1;
    for (int i = Edge::head[x]; i; i = edges[i].next)
    {
        if (edges[i].to == fr) continue;
        rst += dfs(edges[i].to, x, dep - 1);
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 3);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= N; i++)
    {
        printf("%d: %.2f%%\n", i, double(dfs(i)) / N * 100);
    }

    return 0;
}