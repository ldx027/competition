#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int next;
    int to;
};

int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;
vector<int> inDeg;

void addEdge(int u, int v)
{
    inDeg[v]++;
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

queue<int> ans;
bool topSort(int N)
{
    queue<int> que;
    for (int i = 0; i < N; i++)
    {
        if (inDeg[i] == 0)
        {
            que.push(i);
        }
    }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        ans.push(cur);

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (--inDeg[edges[i].to] == 0)
            {
                que.push(edges[i].to);
            }
        }
        Edge::head[cur] = 0;
    }
    for (int i = 0; i < N; i++) if (Edge::head[i]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    Edge::head.resize(N, 0);
    edges.resize(M + 1);
    inDeg.resize(N, 0);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    topSort(N);

    while (!ans.empty())
    {
        cout << ans.front();
        ans.pop();
    }

    return 0;
}

