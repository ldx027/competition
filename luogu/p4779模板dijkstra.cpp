#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAXN 1000100
#define inf 0x3f3f3f3f
#define LL long long

struct Edge
{
    static int cur;
    static int head[MAXN];
    LL to = 0;
    LL wei = 0;
    LL next = 0;
} edge[MAXN];
int Edge::cur = 1;
int Edge::head[MAXN] = { 0 };

void addEdge(LL u, LL v, LL w)
{
    edge[Edge::cur].to = v;
    edge[Edge::cur].wei = w;
    edge[Edge::cur].next = Edge::head[u];
    Edge::head[u] = Edge::cur++;
}

struct Node
{
    LL id, dis;
    Node(LL _id) : id(_id) { dis = inf; }
    bool operator>(const Node &node) const { return this->dis > node.dis; }
};

vector<Node*> vec;
vector<bool> visit;
priority_queue<Node, vector<Node>, greater<Node>> heap;
int main()
{
    LL n, m, s;
    cin >> n >> m >> s;
    vec.resize(n + 1);
    visit.resize(n + 1, false);
    for (LL i = 1; i <= n; i++) vec[i] = new Node(i);
    vec[s]->dis = 0;
    heap.push(*vec[s]);

    LL u, v, w;
    for (LL i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    while (!heap.empty())
    {
        Node node = heap.top();
        heap.pop();
        if (visit[node.id]) continue;
        visit[node.id] = true;

        for (LL i = Edge::head[node.id]; i != 0; i = edge[i].next)
        {
            LL j = edge[i].to;
            LL w = edge[i].wei;
            if (vec[j]->dis > vec[node.id]->dis + w)
            {
                vec[j]->dis = vec[node.id]->dis + w;
                heap.push(*vec[j]);
            }
        }
    }

    for (LL i = 1; i <= n; i++)
    {
        cout << (vec[i]->dis == inf ? 2147483647 : vec[i]->dis)<< " ";
    }

    return 0;
}