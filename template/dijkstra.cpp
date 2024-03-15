#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define inf 0x3f3f3f3f

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

vector<int> dis;

void addEdge(int u, int v, int w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, s});
    dis[s] = 0;

    while (!heap.empty())
    {
        int cur = heap.top().second;
        heap.pop();
        if (vst[cur]) continue;
        vst[cur] = true;

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (dis[edges[i].to] > dis[cur] + edges[i].w)
            {
                dis[edges[i].to] = dis[cur] + edges[i].w;
                heap.push({dis[edges[i].to], edges[i].to});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, s;
    cin >> N >> M >> s;

    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 3);
    dis.resize(N + 1, inf);
    vst.resize(N + 1, false);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    dijkstra(s);

    for (auto it = dis.begin() + 1; it != dis.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}