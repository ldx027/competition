#include <iostream>
#include <deque>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    deque<pair<int, int>> que;

    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        while (!que.empty() && i - que.front().second > m) que.pop_front();

        cout << (que.empty() ? 0 : que.front().first) << "\n";

        while (!que.empty() && que.back().first >= x) que.pop_back();
        que.push_back({x, i});
    }

    return 0;
}