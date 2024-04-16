#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    int x = 0, y = 0;
    int dir = 0;
    vector<vector<int>> vec(n, vector<int>(n, -1));

    for (int cur = 1; cur <= n * n; cur++)
    {
        vec[x][y] = cur;
        if (x + dx[dir] >= n || x + dx[dir] < 0 || y + dy[dir] >= n || y + dy[dir] < 0 || vec[x + dx[dir]][y + dy[dir]] != -1) dir++;
        dir %= 4;
        x += dx[dir];
        y += dy[dir];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2 - log10(vec[i][j]); k++) cout << " ";
            cout << vec[i][j];
        }
        cout << endl;
    }

    return 0;
}