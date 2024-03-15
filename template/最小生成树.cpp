#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

vector<int> frd;

int findFrd(int u)
{
    return frd[u] == 0 ? u : findFrd(frd[u]);
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

    int cnt = 0;
    int sum = 0;

    for (int i = 0; i < M; i++)
    {
        if (!isFrd(edges[i].u, edges[i].v))
        {
            sum += edges[i].w;
            mkFrd(edges[i].u, edges[i].v);
            cnt++;
        }
    }

    if (cnt == N - 1) cout << sum << endl;
    else cout << "orz" << endl;

    return 0;
}