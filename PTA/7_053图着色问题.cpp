#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

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

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

vector<int> color;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int V, E, K;
    cin >> V >> E >> K;
    Edge::head.resize(V + 1, 0);
    edges.resize(2 * E + 3);
    color.resize(V + 1);

    int u, v;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        bool flg = true;
        unordered_set<int> cols;
        for (int j = 1; j <= V; j++)
        {
            cin >> color[j];
            cols.insert(color[j]);
        }
        if (cols.size() != K)
        {
            cout << "No\n";
            continue;
        }
        for (int j = 1; j <= V; j++)
        {
            for (int u = Edge::head[j]; u; u = edges[u].next)
            {
                if (color[j] == color[edges[u].to])
                {
                    flg = false;
                    break;
                }
            }
            if (!flg)
                break;
        }
        cout << (flg ? "Yes" : "No") << endl;
    }

    return 0;
}