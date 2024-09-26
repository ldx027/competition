#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define ll long long
#define inf 0x7f7f7f7f

struct Edge
{
    static ll cnt;
    static vector<ll> head;
    ll to;
    ll w;
    ll next;
};

ll Edge::cnt = 1;
vector<ll> Edge::head;
vector<Edge> edges;

void addEdge(ll u, ll v, ll w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

vector<ll> vec;

ll dijkstra(ll l, ll r, ll S)
{
    if (l > r)
        return -1;
    ll mid = l + ((r - l) >> 1);
    if (vec[1] > mid)
        return dijkstra(vec[1], r, S);

    vector<ll> dis(vec.size(), inf);
    dis[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> heap;
    heap.push({0, 1});

    while (!heap.empty())
    {
        ll cur = heap.top().second;
        heap.pop();

        if (cur == vec.size() - 1)
            return l == r ? l : dijkstra(l, mid, S);

        for (ll i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (vec[edges[i].to] > mid)
                continue;
            
            if (dis[edges[i].to] > dis[cur] + edges[i].w && dis[cur] + edges[i].w <= S)
            {
                dis[edges[i].to] = dis[cur] + edges[i].w;
                heap.push({dis[edges[i].to], edges[i].to});
            }
        }
    }

    return dijkstra(mid + 1, r, S);
}

int main()
{
    ll n, m, b;
    cin >> n >> m >> b;

    Edge::head.resize(n + 1, 0);
    edges.resize(2 * m + 1);
    vec.resize(n + 1);

    ll Max = 0;
    for (ll i = 1; i <= n; i++)
        cin >> vec[i], Max = max(Max, vec[i]);

    ll u, v, w;
    for (ll i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    ll ans = dijkstra(0, Max, b);
    if (ans == -1)
        cout << "AFK" << endl;
    else
        cout << ans << endl;

    return 0;
}