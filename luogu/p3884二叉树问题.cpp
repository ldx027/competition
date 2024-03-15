#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define inf 0x3f3f3f3f

struct Edge
{
    static int cur;
    static vector<int> head;
    int to;
    int next;
};
int Edge::cur = 1;
vector<int> Edge::head;
vector<Edge> edges;

void addEdge(int u, int v)
{
    edges[Edge::cur].to = v;
    edges[Edge::cur].next = Edge::head[u];
    Edge::head[u] = Edge::cur++;
}

vector<int> width;
void dfs(int u, int fat, int dep)
{
    width[dep]++;
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        if (edges[i].to == fat)
            continue;
        dfs(edges[i].to, u, dep + 1);
    }
}

int dis(int u, int fa, int v)
{
    if (u == v)
        return 0;
    int ans = inf;
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        if (edges[i].to == fa) continue;
        ans = min(ans, 1 + (edges[i].to < u) + dis(edges[i].to, u, v));
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    Edge::head.resize(N + 1);
    edges.resize(N * N + 3);
    width.resize(N + 2, 0);

    int u, v;
    for (int i = 1; i < N; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    
    dfs(1, 0, 0);
    auto it = width.begin();
    for (; it != width.end() && *it != 0; it++);
    width.erase(it, width.end());
    cout << width.size() << endl << *max_element(width.begin(), width.end()) << endl;
    

    int x, y;
    cin >> x >> y;
    cout << dis(x, 0, y) << endl;
}