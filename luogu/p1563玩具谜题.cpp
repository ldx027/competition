#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int dir(int p)
{
    if (p == 1) return p;
    return -1;
}

int range(long long x, long long mx)
{
    while (x < 0) x += mx;
    if (x >= mx) x %= mx;
    return x;
}


int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;

    vector<pair<int, string>> vec;

    for (int i = 0; i < n; i++)
    {
        int p;
        string name;
        cin >> p >> name;
        vec.push_back({p, name});
    }

    long long idx = 0;
    for (int i = 0; i < m; i++)
    {
        int p, d;
        cin >> p >> d;
        idx -= dir(p) * dir(vec[idx].first) * d;
        idx = range(idx, n);
        // cout << vec[idx].second << endl;
    }

    cout << vec[idx].second << endl;

    return 0;
}