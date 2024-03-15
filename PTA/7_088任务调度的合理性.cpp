#include <iostream>
#include <vector>
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
vector<bool> vst;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

bool dfs(int u)
{
    // cout << "wtf" << u << endl;
    if (vst[u]) return false;
    vst[u] = true;
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        if (!dfs(edges[i].to)) return false;
    }
    vst[u] = 0;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    Edge::head.resize(N + 1, 0);
    edges.resize(N * N + 2 * N);
    vst.resize(N + 1, false);

    int k, x;
    for (int i = 1; i <= N; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> x;
            addEdge(i, x);
        }
    }
    for (int i = 1; i <= N; i++) addEdge(0, i);

    cout << dfs(0) << endl;

    return 0;
}