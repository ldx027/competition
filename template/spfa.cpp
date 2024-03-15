#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define inf 0x3f3f3f3f

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
    int w;
};

int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;

void addEdge(int u, int v, int w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

vector<int> dis;
vector<int> cnt;
vector<bool> vst;

bool spfa(int s)
{
    queue<int> que;
    que.push(s);
    vst[s] = true;
    dis[s] = 0;
    cnt[s] = 1;
    int N = dis.size();

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vst[cur] = false;
        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (dis[cur] + edges[i].w < dis[edges[i].to])
            {
                dis[edges[i].to] = dis[cur] = edges[i].w;
                cnt[edges[i].to] = cnt[cur] + 1;
                if (cnt[edges[i].to] == N) return false;
                if (!vst[edges[i].to]) que.push(edges[i].to), vst[edges[i].to] = true;;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    int s, t;
    cin >> N >> M >> s >> t;;

    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 3);
    dis.resize(N + 1, inf);
    cnt.resize(N + 1, 0);
    vst.resize(N + 1, false);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    cout << dis[t] << endl;

    return 0;
}