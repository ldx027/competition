#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long
#define mod 80112002

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
vector<ll> dp;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
    inDgr[v]++;
}

int main()
{
    int n, m;
    cin >> n >> m;

    Edge::head.resize(n + 1, 0);
    edges.resize(m + 1);
    inDgr.resize(n + 1, 0);
    dp.resize(n + 1, 0);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addEdge(v, u);
    }

    queue<int> que;
    for (int i = 1; i <= n; i++)
        if (inDgr[i] == 0) que.push(i), dp[i] = 1;
    
    ll ans = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            inDgr[edges[i].to]--;
            dp[edges[i].to] += dp[cur];
            dp[edges[i].to] %= mod;

            if (inDgr[edges[i].to] == 0)
                que.push(edges[i].to);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (Edge::head[i] == 0) ans += dp[i], ans %= mod;
    }

    cout << ans << endl;

    return 0;
}