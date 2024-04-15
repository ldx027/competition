#include <iostream>
#include <vector>
using namespace std;

#define inf 0x3f3f3f3f

struct Edge
{
    static int cur;
    static vector<int> head;
    int to;
    int next = 0;
};
int Edge::cur = 1;
vector<int> Edge::head;
vector<Edge> edges;

void addEdge(int u, int v)
{
    edges[Edge::cur].to = v;
    edges[Edge::cur].next = Edge::head[u];
    Edge::head[u] = Edge::cur++;
}

vector<int> vec;
vector<int> dis;
vector<int> size;

void dfs(int u = 1, int fa = 0, int dep = 0)
{
    size[u] = vec[u];
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        if (edges[i].to == fa) continue;
        dfs(edges[i].to, u, dep + 1);
        size[u] += size[edges[i].to];
    }
    dis[1] += vec[u] * dep;
}

int ans = inf;
void dp(int u = 1, int fa = 0)
{
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        if (edges[i].to == fa) continue;
        dis[edges[i].to] = dis[u] + size[1] - size[edges[i].to] * 2;
        dp(edges[i].to, u);
    }
    ans = min(ans, dis[u]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1);
    dis.resize(N + 1);
    size.resize(N + 1);
    Edge::head.resize(N + 1);
    edges.resize(N * N + 3);

    int u, v;
    for (int i = 1; i <= N; i++)
    {
        cin >> vec[i] >> u >> v;
        if (u)
        {
            addEdge(i, u);
            addEdge(u, i);
        }
        if (v)
        {
            addEdge(i, v);
            addEdge(v, i);
        }
    }

    dfs();
    dp();

    cout << ans << endl;

    return 0;
}
