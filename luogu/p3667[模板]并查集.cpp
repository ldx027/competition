#include <iostream>
#include <vector>
using namespace std;

vector<int> frd;

int findFrd(int u) { return frd[u] == 0 ? u : frd[u] = findFrd(frd[u]); }

void addFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u == v) return ;
    frd[u] = v;
}

bool isFrd(int u, int v)
{
    return findFrd(u) == findFrd(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    frd.resize(N + 1, 0);

    int x, y, z;
    for (int i = 0; i < M; i++)
    {
        cin >> z >> x >> y;
        if (z == 1) addFrd(x, y);
        else if (z == 2) cout << (isFrd(x, y) ? "Y" : "N") << endl;
    }

    return 0;
}