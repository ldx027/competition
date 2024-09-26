#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
using namespace std;

#define ll long long

priority_queue<int> heap;
unordered_map<int, int> c;
unordered_set<int> st;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll x, y;
    for (int i = 0; i < n; i++)
    {
        // t c
        cin >> x >> y;
        if (!st.count(x))
        {
            heap.push(x);
            st.insert(x);
        }
        c[x] += y;
    }

    ll cost = 0;

    while (cost < m)
    {
        int cur = heap.top();
        if (cur == k || cost + c[cur] > m)
            break;
        heap.pop();

        cost += c[cur];
        if (!st.count(cur - 1))
        {
            heap.push(cur - 1);
            st.insert(cur - 1);
        }
        c[cur - 1] += c[cur];
    }

    cout << heap.top() << endl;

    return 0;
}