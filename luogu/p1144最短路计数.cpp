#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define inf 0x3f3f3f3f

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
};

vector<Edge> edges;
int Edge::cnt = 1;
vector<int> Edge::head;

vector<bool> vst;
vector<int> dis;
vector<int> ans;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    edges.resize(2 * M + 3);
    Edge::head.resize(N + 1, 0);
    ans.resize(N + 1);
    vst.resize(N + 1, false);
    dis.resize(N + 1, inf);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    dis[1] = 0;
    ans[1] = 1;
    heap.push({0, 1});
    while (!heap.empty())
    {
        int cur = heap.top().second;
        heap.pop();

        if (vst[cur])
            continue;
        vst[cur] = 1;

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (dis[edges[i].to] > dis[cur] + 1)
            {
                dis[edges[i].to] = dis[cur] + 1;
                ans[edges[i].to] = ans[cur];
                heap.push({dis[edges[i].to], edges[i].to});
            }

            // dont forget this step
            else if (dis[edges[i].to] == dis[cur] + 1)
            {
                ans[edges[i].to] += ans[cur];
                ans[edges[i].to] %= 100003;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}