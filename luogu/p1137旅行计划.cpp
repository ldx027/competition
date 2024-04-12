#include <iostream>
#include <vector>
#include <queue>
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
vector<int> inDeg;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
    inDeg[v]++;
}

vector<int> dis;

bool kahn(int N)
{
    queue<int> que;
    for (int i = 1; i <= N; i++)
    {
        if (inDeg[i] == 0)
        {
            que.push(i);
            dis[i] = 1;
        }
    }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            inDeg[edges[i].to]--;
            if (inDeg[edges[i].to] == 0)
            {
                que.push(edges[i].to);
                // dis[edges[i].to] = dis[cur] + 1;
            }
            dis[edges[i].to] = max(dis[edges[i].to], dis[cur] + 1);
        }
        Edge::head[cur] = 0;
    }

    for (int i = 1; i <= N; i++)
        if (Edge::head[i])
            return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    Edge::head.resize(N + 1, 0);
    edges.resize(M + 1);
    inDeg.resize(N + 1, 0);
    dis.resize(N + 1, 0);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    kahn(N);

    for (int i = 1; i <= N; i++) cout << dis[i] << endl;

    return 0;
}