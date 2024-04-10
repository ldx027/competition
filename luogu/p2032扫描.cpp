#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, x;
    cin >> n >> k;

    deque<pair<int, int>> que;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!que.empty() && que.front().second <= i - k)
            que.pop_front();
        while (!que.empty() && que.back().first < x)
            que.pop_back();
        que.push_back({x, i});
        if (i >= k - 1)
            cout << que.front().first << endl;
    }

    return 0;
}