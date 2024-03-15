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
int Edge::cnt = 1;
vector<int> Edge::head;
vector<Edge> edges;

void addEdge(int u, int v)
{
    edges[Edge::cnt].to = v;
    edges[Edge::cnt].next = Edge::head[u];
    Edge::head[u] = Edge::cnt++;
}

vector<bool> est;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Edge::head.resize(N + 1, 0);
    edges.resize(2 * M + 3);
    est.resize(N + 1, true);

    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    int K, np, x;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <= N; j++) est[j] = true;
        cin >> np;
        bool flg = true;
        for (int j = 0; j < np; j++)
        {
            cin >> x;
            est[x] = false;
        }
        for (int j = 1; j <= N; j++)
        {
            if (!est[j]) continue;
            for (int u = Edge::head[j]; u; u = edges[u].next)
            {
                if (!est[edges[u].to]) continue;
                flg = false;
                break;
            }
            if (!flg) break;
        }
        cout << (flg ? "YES" : "NO") << endl;
    }

    return 0;
}