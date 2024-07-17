#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
    int val;

    const bool operator<(const Node &other) const
    {
        return val > other.val;
    }
};

int main()
{
    int R, C;
    cin >> R >> C;

    int val;
    vector<vector<long long>> map(R + 2, vector<long long>(C + 2, 0));
    vector<vector<long long>> dp(R + 2, vector<long long>(C + 2, 0));
    priority_queue<Node> heap;

    for (int i = 1; i <= R; i++)
    {
        for (int j  = 1; j <= C; j++)
        {
            cin >> val;
            map[i][j] = val;
            heap.push({i, j, val});
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int x, y;
    while (!heap.empty())
    {
        x = heap.top().x;
        y = heap.top().y;
        val = heap.top().val;
        heap.pop();

        for (int i = 0; i < 4; i++)
            if (map[x][y] > map[x + dx[i]][y + dy[i]])
                dp[x][y] = max(dp[x][y], dp[x + dx[i]][y + dy[i]]);
        dp[x][y]++;
    }

    long long ans = 0;
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) ans = max(ans, dp[i][j]);

    cout << ans << endl;

    return 0;
}