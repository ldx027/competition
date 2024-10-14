#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

vector<pair<int, int>> road;
vector<int> vec;
vector<int> frd;

int findFrd(int u) { return frd[u] == u ? u : frd[u] = findFrd(frd[u]); }
bool isFrd(int u, int v) { return findFrd(u) == findFrd(v); }
void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u != v)
        frd[u] = v;
}

int main()
{
    int n, m;
    cin >> n >> m;

    frd.resize(n);
    for (int i = 0; i < n; i++)
        frd[i] = i;
    
    road.resize(m);
    for (int i = 0; i < m; i++)
        cin >> road[i].first >> road[i].second;
    
    int k;
    cin >> k;

    vec.resize(k);
    unordered_set<int> st;
    for (int i = 0; i < k; i++)
    {
        cin >> vec[i];
        st.insert(i);
    }

    // --------

    for (int i = 0; i < m; i++)
    {
        int a = road[i].first;
        int b = road[i].second;
        if (st.count(a) || st.count(b))
    }
}