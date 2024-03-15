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
    int w;
    int next;
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
queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    Edge::head.resize(n + 1, 0);
    edges.resize(2 * m + 3);
    dis.resize(n + 1, inf);
    cnt.resize(n + 1, 0);
    vst.resize(n + 1, false);

    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    bool flg = true;
    que.push(s);
    dis[s] = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        vst[cur] = false;

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (dis[edges[i].to] > dis[cur] + edges[i].w)
            {
                dis[edges[i].to] = dis[cur] + edges[i].w;
                cnt[edges[i].to] = cnt[cur] + 1;
                if (cnt[edges[i].to] >= n)
                {
                    flg = true;
                    break;
                }
                if (!vst[edges[i].to])
                {
                    que.push(edges[i].to);
                    vst[edges[i].to] = true;
                }
            }
        }
        if (!flg)
            break;
    }

    cout << dis[t] << endl;

    return 0;
}