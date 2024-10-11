#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define inf 0x3f3f3f3f

int m, n;
vector<vector<int>> mp, dis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs()
{
    queue<pair<pair<int, int>, int>> que;
    dis[1][1] = 0;
    que.push({{1, 1}, 0});

    int cx, cy, nx, ny;
    while (!que.empty())
    {
        cx = que.front().first.first;
        cy = que.front().first.second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (nx == 0 || ny == 0 || nx > m || ny > m)
                continue;

            int ndis = dis[cx][cy];

            if (mp[cx][cy] == 0 && mp[nx][ny] != 0)
                ndis += (mp[bx][by] != mp[nx][ny]);
            else if(mp[cx][cy] == 0 && mp[nx][ny] == 0)
                ndis = inf;
            else if (mp[cx][cy] != 0 && mp[nx][ny] == 0)
                ndis += 2;
            else if (mp[cx][cy] != mp[nx][ny])
                ndis += 1;
            else
                ndis += 0;

            if (ndis < dis[nx][ny])
            {
                dis[nx][ny] = ndis;
                que.push({{nx, ny}, mp[cx][cy]});
            }
        }
    }
}

int main()
{
    cin >> m >> n;

    mp.resize(m + 1, vector<int>(m + 1, 0));
    dis.resize(m + 1, vector<int>(m + 1, inf));

    int x, y, c;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> c;
        mp[x][y] = c + 1;
    }

    bfs();

    if (dis[m][m] != inf)
        cout << dis[m][m] << endl;
    else
        cout << -1 << endl;
    
    return 0;
}