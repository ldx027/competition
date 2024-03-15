#include <iostream>
#include <vector>
using namespace std;

void show(vector<vector<long long>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            printf("%10ld", vec[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> vec(n + 3, vector<long long>(m + 3, 0));
    vec[0][0] = 1;
    int x, y;
    cin >> x >> y;
    vec[x][y] = -1;
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] >= 0 && x + dx[i] <= n && y + dy[i] >= 0 && y + dy[i] <= m)
        {
            vec[x + dx[i]][y + dy[i]] = -1;
        }
    }
    // show(vec);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if ((i == 0 && j == 0) || vec[i][j] == -1) continue;
            long long a1 = 0, a2 = 0;
            if (i - 1 >= 0 && vec[i - 1][j] != -1)
            {
                a1 = vec[i - 1][j];
            }
            if (j - 1 >= 0 && vec[i][j - 1] != -1)
            {
                a2 = vec[i][j - 1];
            }
            vec[i][j] = a1 + a2;
    // show(vec);
        }
    }

    // show(vec);
    cout << vec[n][m] << endl;

    return 0;

}