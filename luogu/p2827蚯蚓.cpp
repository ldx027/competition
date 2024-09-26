#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

int main()
{
    ll n, m, q, u, v, t;
    double p = (double)u / v;
    cin >> n >> m >> q >> u >> v >> t;

    priority_queue<ll> heap;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        heap.push(x);
    }

    ll cnt = 0;

    t = 1;
    ll cur;
    for (int i = 0; i * t < m; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cur = heap.top();
            heap.pop();
            heap.push((cur + cnt * q) * p - (cnt + 1) * q);
            heap.push(cur + cnt * q - int((cur + cnt * q) * p) - (cnt + 1) * q);
        }
        cout << cur + q * cnt << " ";
        cnt += t;
    }
    cout << endl;

    return 0;
}