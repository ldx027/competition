#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

vector<int> frd;

int findFrd(int u) { return frd[u] != u ? frd[u] = findFrd(frd[u]) : u; }
bool isFrd(int u, int v) { return findFrd(u) == findFrd(v); }
void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u != v)
        frd[u] = v;
}

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

int n, m, k;
vector<int> vec;
unordered_set<int> st;

int main()
{
    cin >> n >> m;

    frd.resize(n);
    for (int i = 0; i < n; i++)
        frd[i] = i;

    Edge::head.resize(n, 0);
    edges.resize(2 * m + 1);

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    cin >> k;
    vec.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> u;
        st.insert(u);
        vec[i] = u;
    }

    int frag = n - k;
    for (int i = 0; i < n; i++)
    {
        if (!st.count(i))
            for (int j = Edge::head[i]; j; j = edges[j].next)
                if (!st.count(edges[j].to) && !isFrd(i, edges[j].to))
                    mkFrd(i, edges[j].to), frag--;
    }
    
    stack<int> ans;
    ans.push(frag);

    for (int i = k - 1; i >= 0; i--)
    {
        st.erase(vec[i]);
        frag++;
        for (int j = Edge::head[vec[i]]; j; j = edges[j].next)
        {
            if (!st.count(edges[j].to) && !isFrd(vec[i], edges[j].to))
            {
                mkFrd(vec[i], edges[j].to), frag--;
            }
        }
        ans.push(frag);
    }
    
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}
