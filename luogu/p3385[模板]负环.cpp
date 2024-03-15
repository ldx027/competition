#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int next;
    int to;
    int w;
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
vector<int> cnt;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M;
        cin >> N >> M;
    }
}
