#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

bool avilable(int x, int y, int mx, int my)
{
    return x >= 0 && x < mx && y >= 0 && y < my;
}

void show(vector<vector<int>> map)
{
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<int>> map(n, vector<int>(m, -1));
    queue<pair<int, int>> que;
    que.push(pair<int, int>(x, y));
    map[x][y] = 0;

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    while (!que.empty())
    {
        pair<int, int> point = que.front();
        que.pop();
        for (int i  = 0; i < 8; i++)
        {
            int x = point.first + dx[i];
            int y = point.second + dy[i];
            if (avilable(x, y, n, m) && map[x][y] == -1)
            {
                map[x][y] = map[point.first][point.second] + 1;
                que.push(pair<int, int>(x, y));
            }
        }
    }
    show(map);

    return 0;
}