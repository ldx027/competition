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
vector<int> rDegree;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
    rDegree[v]++;
}

queue<int> ans;
bool kahn(int N)
{
    queue<int> que;
    for (int i = 1; i <= N; i++)
    {
        if (rDegree[i] == 0) que.push(i), ans.push(i);
    }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            rDegree[edges[i].to]--;
            if (rDegree[edges[i].to] == 0) que.push(edges[i].to), ans.push(edges[i].to);
        }
        Edge::head[cur] = 0;
    }

    for (int i = 1; i <= N; i++) if (Edge::head[i]) return false;
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
    rDegree.resize(N + 1, 0);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    kahn(N);
    
    while (!ans.empty())
    {
        cout << ans.front() << " ";
        ans.pop();
    }

    return 0;
}