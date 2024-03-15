#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define inf 0x3f3f3f3f

vector<long long> dis;
vector<long long> num;
vector<bool> vst;
int edgeCnt = 0;
priority_queue<pair<long long, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, E;
    cin >> N >> E;
    edge.resize(N + 1, {0, 0});
    dis.resize(N + 1, inf);
    num.resize(N + 1, 0);
    vst.resize(N + 1, false);

    long long u, v, w;
    for (long long i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    dis[1] = 0;
    num[1] = 1;
    heap.push({0, 1});

    while (!heap.empty())
    {
        long long cur = heap.top().second;
        heap.pop();
        if (vst[cur])
            continue;
        vst[cur] = true;

        for (long long i = Edge::head[cur]; i; i = edges[i].next)
        {
            long long to = edges[i].to;
            if (dis[to] == dis[cur] + edges[i].w)
            {
                num[to] += num[cur];
                heap.push({dis[to], to});
            }
            else if (dis[to] > dis[cur] + edges[i].w)
            {
                dis[to] = dis[cur] + edges[i].w;
                num[to] = num[cur];
                heap.push({dis[to], to});
            }
        }
    }

    if (dis[N] != inf)
        cout << dis[N] << " " << num[N] << endl;
    else
        cout << "No answer" << endl;
    return 0;
}