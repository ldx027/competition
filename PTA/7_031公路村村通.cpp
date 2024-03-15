#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};
vector<Edge> edges;

bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}

vector<int> frd;

void addFrd(int u, int v)
{
    while (frd[u])
        u = frd[u];
    while (frd[v])
        v = frd[v];
    if (u == v)
        return;
    frd[v] = u;
}

bool isFrd(int u, int v)
{
    while (frd[u])
        u = frd[u];
    while (frd[v])
        v = frd[v];
    return u == v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    frd.resize(N + 1, 0);
    edges.resize(M);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end(), cmp);

    int cost = 0;
    int total = 0;
    for (int i = 0; i < M; i++)
    {
        if (isFrd(edges[i].u, edges[i].v))
            continue;
        total++;
        addFrd(edges[i].u, edges[i].v);
        cost += edges[i].w;
    }

    if (total == N - 1)
        cout << cost << endl;
    else
    {
        cout << -1 << endl;
    }

    return 0;
}