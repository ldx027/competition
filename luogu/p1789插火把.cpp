#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool torch[5][5] = 
    {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
    };

    int n, m, k;
    int x, y;
    cin >> n >> m >> k;

    vector<vector<bool>> vec(n, vector<bool>(n, false));

    while (m--)
    {
        cin >> x >> y;
        x--, y--;
        for (int i = x - 2; i < x + 3; i++)
        {
            for (int j = y - 2; j < y + 3; j++)
            {
                if (i >= n || i < 0 || j >= n || j < 0) continue;
                if (torch[i - x + 2][j - y + 2]) vec[i][j] = true;
            }
        }
    }

    while (k--)
    {
        cin >> x >> y;
        x--, y--;
        for (int i = x; i < x + 5; i++)
        {
            for (int j = y; j < y + 5; j++)
            {
                if (i >= n || i < 0 || j >= n || j < 0) continue;
                vec[i][j] = true;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // cout << vec[i][j] << " ";
            if (!vec[i][j]) cnt++;
        }
        // cout << endl;
    }

    cout << cnt << endl;


    return 0;
}