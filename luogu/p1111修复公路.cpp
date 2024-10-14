#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Road
{
    int x, y, t;
};

bool cmp(Road a, Road b)
{
    return a.t < b.t;
}

int n, m;
vector<int> frd;
vector<Road> roads;

inline int findFrd(int u) { return !frd[u] ? u : frd[u] = findFrd(frd[u]); }

void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u == v)
        return;
    frd[u] = v;
}

inline bool isFrd(int u, int v) { return findFrd(u) == findFrd(v); }

int main()
{
    cin >> n >> m;

    frd.resize(n + 1, 0);
    roads.resize(m);

    for (int i = 0; i < m; i++)
        cin >> roads[i].x >> roads[i].y >> roads[i].t;
    
    sort(roads.begin(), roads.end(), cmp);

    int ans, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (!isFrd(roads[i].x, roads[i].y))
        {
            mkFrd(roads[i].x, roads[i].y);
            cnt++;
            ans = roads[i].t;
        }
    }

    if (cnt == n - 1)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}