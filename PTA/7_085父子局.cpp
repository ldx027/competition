#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> frd;

int find(int x)
{
    return frd[x] == 0 ? x : frd[x] = find(frd[x]);
}

void addFrd(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    frd[v] = u;
}

bool isFrd(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
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

    int n, m;
    cin >> n >> m;
    frd.resize(n + 1, 0);
    edges.resize(m);
    for (int i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), cmp);

    int total = 0;
    int rst = 0;
    for (int i = 0; i < m; i++)
    {
        if (isFrd(edges[i].u, edges[i].v))
            continue;
        total++;
        rst += edges[i].w;
        addFrd(edges[i].u, edges[i].v);
    }

    if (total == n - 1)
        cout << rst << endl;
    else
        cout << "dh yyds" << endl;

    return 0;
}