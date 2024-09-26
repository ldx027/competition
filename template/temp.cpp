#include <iostream>
#include <vector>
using namespace std;

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
    edges[Edge::cnt].next = v;
    edges[Edge::cnt].w = w;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}