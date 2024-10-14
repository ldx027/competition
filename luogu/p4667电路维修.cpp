#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <utility>
using namespace std;

int n, m;
vector<vector<bool>> map;
vector<vector<bool>> vst;

int main()
{
    cin >> n >> m;

    map.resize(n, vector<bool>(m)); 
    vst.resize(n + 1, vector<bool>(m + 1, false)); 

    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            map[i][j] = (c == '\\');
        }
    }

    if ((n + m) & 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    deque<pair<pair<int, int>, int>> que;
    que.push_back({{0, 0}, 0});

    int x, y, dis;
    while (!que.empty())
    {
        x = que.front().first.first;
        y = que.front().first.second;
        dis = que.front().second;
        que.pop_front();

        // cout << x << " " << y << " " << dis << endl;

        if (x < 0 || y < 0 || vst[x][y])
            continue;
        
        vst[x][y] = true;

        if (x == n && y == m)
        {
            cout << dis << endl;
            return 0;
        }

        if (x < n && y < m)
        {
            if (map[x][y])
                que.push_front({{x + 1, y + 1}, dis});
            else
                que.push_back({{x + 1, y + 1}, dis + 1});
        }

        if (x < n && y > 0)
        {
            if (!map[x][y - 1])
                que.push_front({{x + 1, y - 1}, dis});
            else
                que.push_back({{x + 1, y - 1}, dis + 1});
        }

        if (x > 0 && y < m)
        {
            if (!map[x - 1][y])
                que.push_front({{x - 1, y + 1}, dis});
            else
                que.push_back({{x - 1, y + 1}, dis + 1});
        }

        if (x > 0 && y > 0)
        {
            if (map[x - 1][y - 1])
                que.push_front({{x - 1, y - 1}, dis});
            else
                que.push_back({{x - 1, y - 1}, dis + 1});
        }
    }

    return 0;
}