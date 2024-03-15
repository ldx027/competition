#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

struct Edge
{
    int u, v, w;
};

bool cmp(Edge &a, Edge &b)
{
    return a.w < b.w;
}

vector<Edge> edges;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    frd.resize(N + 1, 0);
    edges.resize(M);

    for (int i = 0; i < M; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    int total = 0;
    int n = 0;
    for (int i = 0; i < M; i++)
    {
        if (isFrd(edges[i].u, edges[i].v)) continue;
        mkFrd(edges[i].u, edges[i].v);
        total += edges[i].w;
        n++;
    }

    cout << total << endl;

    return 0;
}