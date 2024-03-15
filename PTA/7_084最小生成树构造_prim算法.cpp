#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int w;
    int next;
};
int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;
vector<bool> vst;

void addEdge(int u, int v, int w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

priority_queue<pair<int, int>> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 1);
    vst.resize(N + 1, false);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    for (int i = Edge::head[1]; i; i = edges[i].next)
    {
        que.push({-edges[i].w, i});
    }

    int total = 0;
    while (!que.empty())
    {
        int idx = que.top().second;
        que.pop();
        if (vst[idx]) continue;

        total++;
    }
}