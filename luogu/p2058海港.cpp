#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int nations[1000000] = { 0 };
int main()
{
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int ans = 0;
    queue<pair<int, long long>> que;
    for (int i = 0; i < N; i++)
    {
        int t, k, x;
        cin >> t >> k;
        while (!que.empty() && que.front().second <= t - 86400)
        {
            nations[que.front().first]--;
            if (nations[que.front().first] == 0)
            {
                ans--;
            }
            que.pop();
        }
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            que.push({x, t});
            nations[x]++;
            if (nations[x] == 1)
            {
                ans++;
            }
        }
        // cout << "ans";
        cout << ans << endl;
    }

    return 0;
}