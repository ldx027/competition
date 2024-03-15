#include <iostream>
#include <vector>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool avilable(int x, int y, int n)
{
    return (x > 0 && x < n - 1 && y > 0 && y < n - 1);
}
void bfs(vector<vector<int>> *map, int x, int y, int n)
{
    if ((*map)[x][y])
        return;
    (*map)[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int _x = x + dx[i];
        int _y = y + dy[i];
        if (!avilable(_x, _y, n))
            continue;
        if ((*map)[_x][_y] == 0)
            bfs(map, _x, _y, n);
    }
}

bool inCircle(vector<vector<int>> *map, int x, int y, int n)
{
    if ((*map)[x][y] == 1)
        return false;
    bool yes_x1 = 0;
    bool yes_x2 = 0;
    bool yes_y1 = 0;
    bool yes_y2 = 0;

    for (int i = 0; i < x; i++)
    {
        if ((*map)[i][y] == 1) yes_x1 = 1;
    }
    for (int i = x + 1; i < n; i++)
    {
        if ((*map)[i][y] == 1) yes_x2 = 1;
    }
    for (int i = 0; i < y; i++)
    {
        if ((*map)[x][i] == 1) yes_y1 = 1;
    }
    for (int i = y + 1; i < n; i++)
    {
        if ((*map)[x][i] == 1) yes_y2 = 1;
    }
    return (yes_x1 && yes_y1 && yes_x2 && yes_y2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (inCircle(&vec, i, j, n))
            {
                bfs(&vec, i, j, n);
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cout << vec[i][j] << " ";
                    }
                    cout << endl;
                }

                return 0;
            }
        }
    }

    return 0;
}