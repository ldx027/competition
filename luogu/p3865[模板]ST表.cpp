#include <iostream>
#include <vector>
using namespace std;

int n, m, x, y;
vector<int> lg;
vector<vector<int>> vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lg.resize(n + 1);
    lg[1] = 0;
    vec.resize(n + 1, vector<int>(20, 0));

    cin >> n >> m;
    for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= n; i++) cin >> vec[i][0];
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 1; j <= n - (1 << i) + 1; j++)
        {
            vec[j][i] = max(vec[j][i - 1], vec[j + (1 << i - 1)][i - 1]);
        }
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        int l = lg[y - x + 1];
        cout << max()
    }

    return 0;
}