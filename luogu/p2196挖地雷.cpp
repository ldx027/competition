#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
    static int cur;
    static vector<int> head;
    int to = 0;
    int next = 0;
};
vector<Edge> edges;
int Edge::cur = 1;
vector<int> Edge::head;

void addEdge(int u, int v)
{
    edges[Edge::cur].to = v;
    edges[Edge::cur].next = Edge::head[u];
    Edge::head[u] = Edge::cur++;
}

void print(vector<int> pre, int n)
{
    if (pre[n]) print(pre, pre[n]);
    if (n != 0) cout << n << " ";
}

vector<int> vec;
vector<int> dp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;
    vec.resize(N + 1);
    dp.resize(N + 1, 0);
    edges.resize(N * N + 3);
    Edge::head.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) cin >> vec[i];

    int x;
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            cin >> x;
            if (x)
            {
                addEdge(i, j);
                addEdge(j, i);
            }
        }
    }

    int ans = vec[1];
    int pos;
    vector<int> pre(N + 1, 0);
    dp[1] =  vec[1];
    for (int i = 2; i <= N; i++)
    {
        dp[i] = vec[i];
        for (int j = Edge::head[i]; j; j = edges[j].next)
        {
            cout << i <<  j << endl;
            if (dp[edges[j].to] + vec[i] > dp[i])
            {
                dp[i] = dp[edges[j].to] + vec[i];
                pre[i] = edges[j].to;
            }
        }
        
        if (ans < dp[i])
        {
            ans = dp[i];
            pos = i;
        }
    }

    print(pre, pos);
    cout << endl << ans << endl;

    return 0;

}