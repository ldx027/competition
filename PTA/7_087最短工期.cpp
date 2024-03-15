#include <iostream>
#include <vector>
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
vector<int> rd;

void addEdge(int u, int v, int w)
{
    rd[v]++;
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

queue<int> que;
vector<int> dis;
int ans = 0;
bool topSort(int N)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (rd[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        cnt++;
        int cur = que.front();
        que.pop();
        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (--rd[edges[i].to] == 0)
            {
                que.push(edges[i].to);
            }
            dis[edges[i].to] = max(dis[edges[i].to], dis[cur] + edges[i].w);
            ans = max(ans, dis[edges[i].to]);
        }
        Edge::head[cur] = 0;
    }

    return cnt == N;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Edge::head.resize(N + 1, 0);
    dis.resize(N + 1, 0);
    rd.resize(N + 1, 0);
    edges.resize(M + 3);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        u++, v++;
        addEdge(u, v, w);
    }

    if (topSort(N))
        cout << ans << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}
