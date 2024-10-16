#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define maxN 100010
// #define debug

struct Edge { ll u, v, r; };
struct Qst { ll k, v, id; };
bool cmpEdge(Edge a, Edge b) { return a.r > b.r; }
bool cmpQst(Qst a, Qst b) { return a.k > b.k; }

vector<ll> w;
vector<ll> frd;

ll findFrd(ll u) { return frd[u] ? frd[u] = findFrd(frd[u]) : u; }
void mkFrd(ll u, ll v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u != v)
        frd[u] = v, w[v] += w[u];
}

ll n, q;
vector<Edge> edges;
vector<Qst> qsts;
vector<ll> ans;

int main()
{
    cin >> n >> q;

    frd.resize(maxN, 0);
    w.resize(maxN, 1);
    edges.resize(maxN);
    qsts.resize(maxN);
    ans.resize(maxN, 1);

    for (ll i = 0; i < n - 1; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].r;
    for (ll i = 0; i < q; i++)
    {
        cin >> qsts[i].k >> qsts[i].v;
        qsts[i].id = i;
    }

    sort(edges.begin(), edges.begin() + n - 1, cmpEdge);
    sort(qsts.begin(), qsts.begin() + q, cmpQst);

    ll cur = 0;
    for (ll i = 0; i < q; i++)
    {
        while (cur < n - 1 && edges[cur].r >= qsts[i].k)
        {
            mkFrd(edges[cur].u, edges[cur].v);
            cur++;
        }
        ans[qsts[i].id] = w[findFrd(qsts[i].v)];
    }

    for (ll i = 0; i < q; i++)
        cout << ans[i] - 1 << endl;

    return 0;
}