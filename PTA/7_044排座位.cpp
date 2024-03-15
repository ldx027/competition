#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> frd;
vector<int> par;

void addFrd(int u, int v)
{
    while (par[u])
        u = par[u];
    while (par[v])
        v = par[v];
    if (u == v)
        return;
    par[v] = u;
}

bool find(int u, int v)
{
    while (par[u])
        u = par[u];
    while (par[v])
        v = par[v];
    return u == v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    frd.resize(N + 1, vector<int>(N + 1, 0));
    par.resize(N + 1, 0);

    int u, v, w;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v >> w;
        frd[u][v] = w;
        frd[v][u] = w;
        if (w == 1) addFrd(u, v);
    }

    for (int i = 0; i < K; i++)
    {
        cin >> u >> v;
        if (find(u, v) && frd[u][v] != -1)
        {
            cout << "No problem" << endl;
        }
        else if (frd[u][v] == -1 && find(u, v))
        {
            cout << "OK but..." << endl;
        }
        else if (frd[u][v] == -1 && !find(u, v))
        {
            cout << "No way" << endl;
        }
        else 
        {
            cout << "OK" << endl;
        }
    }

    return 0;
}