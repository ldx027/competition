#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<short>> vec(n, vector<short>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> vec[i][j];

    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + vec[i][j];
        }
    }

    int ans = 0;
    for (int l = 1; l <= min(n, m); l++)
    {
        for (int i = 0; i + l < n; i++)
        {
            for (int j = 0; j + l < m; j++)
            {
                if (sum[i + l][j + l] - sum[i + l][j] - sum[i][j + l] + sum[i][j] == l * l) ans = max(ans, l);
            }
        }
    }

    cout << ans << endl;

    return 0;
}