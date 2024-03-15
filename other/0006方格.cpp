#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool xl(int m, int n, int x, int y)
{
    return (abs(m - x) + abs(n - y)) == 1;
}

int tempx[20] = {0};

int main()
{
    int n, m;
    int x;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> ansvec(n, vector<int>(m, 0));
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            tempx[x]++;
            map[i][j] = x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ansvec[i][j] = tempx[map[i][j]] - 1;
        }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int x = i-1; x < min(n, i + 2); x++)
            {
                for (int y = j-1; y < min(m, j + 2); y++)
                {
                    if (x >= 0 && y >= 0 && xl(i, j, x, y) && map[i][j] == map[x][y])
                    {
                        ansvec[i][j]--;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ansvec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans += ansvec[i][j];
        }
    }

    cout << ans;

    return 0;
}