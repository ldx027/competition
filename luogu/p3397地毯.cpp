#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> diff;

// vec[i][j] = diff[i][j] - diff[i - 1][j] - diff[i][j - 1] + diff[i][j];
//                +              -                 -             +

int main()
{
    cin >> n >> m;

    diff.resize(n + 2, vector<int>(n + 2, 0));

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        diff[x1][y1]++;
        diff[x2 + 1][y1]--;
        diff[x1][y2 + 1]--;
        diff[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
                diff[i][j] += diff[i - 1][j];
                diff[i][j] += diff[i][j -1];
                diff[i][j] -= diff[i - 1][j - 1];
            
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}