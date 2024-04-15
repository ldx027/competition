#include <iostream>
#include <vector>
using namespace std;

vector<int> lg;
vector<vector<int>> vec;

int main()
{
    int n, m;
    cin >> n >> m;

    lg.resize(n + 1);
    vec.resize(n + 1, vector<int>(20));

    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i >> 1] + 1;

    for (int i = 1; i  <= n; i++)
    {
        cout << i << " " << lg[i] << endl;
    }

    for (int i = 1; i <= n; i++)
        cin >> vec[i][0];

    for (int j = 1; j <= lg[n]; j++)
    {
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            vec[i][j] = max(vec[i][j - 1], vec[i + (1 << (j - 1))][j - 1]);
        }
    }

    int x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int l = lg[y - x + 1];
        cout << max(vec[x][l], vec[y - (1 << l) + 1][l]) << endl;
    }
}