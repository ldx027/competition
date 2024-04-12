#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}

vector<Edge> edges;

vector<int> frd;

int findFrd(int u)
{
    return frd[u] == 0 ? u : frd[u] = findFrd(frd[u]);
}

void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u == v) return;
    frd[u] = v;
}

bool isFrd(int u, int v)
{
    return findFrd(u) == findFrd(v);
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

    int rst = 0;
    for (int i = 0; i < M; i++)
    {
        if (!isFrd(edges[i].u, edges[i].v))
        {
            rst += edges[i].w;
            mkFrd(edges[i].u, edges[i].v);
        }
    }

    cout << rst << endl;

    return 0;
}