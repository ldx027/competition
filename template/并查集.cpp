#include <iostream>
#include <vector>
using namespace std;

vector<int> frd;

int findFrd(int u)
{
    return frd[u] == 0 ? u : findFrd(frd[u]);
}

void mkFrd(int u, int v)
{
    u = findFrd(u);
    v = findFrd(v);
    if (u == v) return;
    frd[v] = u;
}

bool isFrd(int u, int v)
{
    return findFrd(u) == findFrd(v);
}

int main()
{
    return 0;
}