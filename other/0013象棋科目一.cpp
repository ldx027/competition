#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define inf 0x3f3f3f3f

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> vec(n + 1, vector<int>(m + 1, inf));
    vec[x][y] = 0;
    queue<pair<int, int>> que;
    que.push({x, y});
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 8; i++)
        {
            int _x = cur.first + dx[i];
            int _y = cur.second + dy[i];
            if (_x > 0 && _x <= n && _y > 0 && _y <= m)
            {
                if (vec[_x][_y] == inf)
                {
                    vec[_x][_y] = vec[cur.first][cur.second] + 1;
                    que.push({_x, _y});
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vec[i][j] == inf) vec[i][j] = -1;
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}