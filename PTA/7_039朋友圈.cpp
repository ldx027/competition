#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> parent;

int findPar(int x)
{
    while (parent[x]) x = parent[x];
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    parent.resize(N + 1, 0);
    vec.resize(N + 1, 0);
    int m, u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> m;
        cin >> u;
        u = findPar(u);
        for (int i = 1; i < m; i++)
        {
            cin >> v;
            v = findPar(v);
            if (v == u) continue;
            parent[v] = u;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        vec[findPar(i)]++;
    }
    
    cout << *max_element(vec.begin(), vec.end());
}