#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    static int cnt;
    static vector<int> head;
    int to;
    int next;
};

vector<int> Edge::head;
vector<Edge> edges;
vector<int> vec;
vector<int> dis;
vector<int> size;

void dfs(int u = 1, int fa = 0)
{
    size[u] = vec[u];
    for (int i = Edge::head[u]; i; i = edges[i].next)
    {
        1 == 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}