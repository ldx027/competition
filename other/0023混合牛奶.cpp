#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int cost;
    int total;
};

bool cmp(Node a, Node b)
{
    return a.cost < b.cost;
}

vector<Node> vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vec.resize(m);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[i].cost = a;
        vec[i].total = b;
    }
    sort(vec.begin(), vec.end(), cmp);

    int idx = 0;
    int ans = 0;
    while (n)
    {
        int use = min(n, vec[idx].total);
        ans += vec[idx++].cost * use;
        n -= use;
    }
    cout << ans << endl;

    return 0;
}