#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stack>
using namespace std;

#define inf 0x3f3f3f3f

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

void addEdge(int u, int v, int w)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

vector<int> dis;
vector<int> num;
vector<int> jyd;
vector<int> fr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, S, D;
    cin >> N >> M >> S >> D;

    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> vec[i];

    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 1);
    dis.resize(N + 1, inf);
    num.resize(N + 1, 1);
    jyd.resize(N + 1, 0);
    fr.resize(N + 1, 0);
    dis[S + 1] = 0;
    jyd[S + 1] = vec[S + 1];

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        u++, v++;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, S + 1});

    while (!heap.empty())
    {
        int cur = heap.top().second;
        if (cur == D + 1) break;
        heap.pop();

        for (int i = Edge::head[cur]; i; i = edges[i].next)
        {
            if (edges[i].w + dis[cur] < dis[edges[i].to])
            {
                dis[edges[i].to] = edges[i].w + dis[cur];
                num[edges[i].to] = 1;
                fr[edges[i].to] = cur;
                jyd[edges[i].to] = jyd[cur] + vec[edges[i].to];

                heap.push({dis[edges[i].to], edges[i].to});
            }
            else if (edges[i].w + dis[cur] == dis[edges[i].to])
            {
                num[edges[i].to]++;
                if (jyd[cur] + vec[edges[i].to] > jyd[edges[i].to])
                {
                    fr[edges[i].to] = cur;
                    jyd[edges[i].to] = jyd[cur] + vec[edges[i].to];
                    heap.push({dis[edges[i].to], edges[i].to});
                }
            }
        }
    }

    cout << num[D + 1] << " " << jyd[D + 1] << endl;

    int cur = D + 1;
    stack<int> stk;

    while (cur)
    {
        stk.push(cur);
        cur = fr[cur];
    }

    bool flg = false;
    while (!stk.empty())
    {
        if (flg) cout << " ";
        cout << stk.top() - 1;
        flg = true;
        stk.pop();
    }

    return 0;
}