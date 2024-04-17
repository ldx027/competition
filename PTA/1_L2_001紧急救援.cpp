#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define inf 0x3f3f3f3f
#define wtf std::cout<<"wtf"<<std::endl

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int w;
    int next;
};

int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;
vector<int> dis;
vector<int> vec;
vector<int> num;
vector<int> fr;
vector<int> vst;

void addEdge(int u, int v, int w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, s});
    dis[s] = 0;

    while (!heap.empty())
    {
        wtf;
        int cur = heap.top().second;
        cout << cur << endl;
        heap.pop();

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (dis[edges[i].to] > dis[cur] + edges[i].w)
            {
                dis[edges[i].to] = dis[cur] + edges[i].w;
                fr[edges[i].to] = cur;
                num[edges[i].to] = num[cur] + vec[edges[i].to];
                heap.push({dis[edges[i].to], edges[i].to});
            }
            else if (dis[edges[i].to] == dis[cur] + edges[i].w)
            {
                if (num[edges[i].to] < num[cur] + vec[edges[i].to])
                {
                    fr[edges[i].to] = cur;
                    num[edges[i].to] = num[cur] + vec[edges[i].to];
                    heap.push({dis[edges[i].to], edges[i].to});
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, D;
    cin >> N >> M >> S >> D;
    S++, D++;

    vec.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> vec[i];

    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 3);
    dis.resize(N + 1, inf);
    fr.resize(N + 1, 0);
    num.resize(N + 1, 0);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        u++, v++;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }

    dijkstra(S);

    cout << dis[D] << endl;

    return 0;
}