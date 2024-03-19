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
vector<int> inDgr;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
    inDgr[v]++;
}

queue<int> topSort(int N)
{
    queue<int> rst;
    queue<int> que;

    for (int i = 1; i <= N; i++)
        if (inDgr[i] == 0)
        {
            que.push(i);
            rst.push(i);
        }

    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (--inDgr[edges[i].to] == 0)
            {
                que.push(edges[i].to);
                rst.push(edges[i].to);
            }
        }
        Edge::head[cur] = 0;
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, x;
    cin >> N;

    Edge::head.resize(N + 1, 0);
    edges.resize(N * N + N);
    inDgr.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        while (cin >> x)
        {
            if (x == 0) break;
            addEdge(i, x);
        }
    }

    queue<int> que = topSort(N);

    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }

    return 0;
}