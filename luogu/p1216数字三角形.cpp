#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int r;
    cin >> r;
    vector<vector<int>> vec(r, vector<int>(r));
    vector<vector<int>> ans(r, vector<int>(r, -1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cin >> vec[i][j];
        }
    }
    ans[0][0] = vec[0][0];
    for (int i = 1; i < r; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0)
            {
                ans[i][j] = ans[i - 1][j] + vec[i][j];
            }
            else if (j == i)
            {
                ans[i][j] = ans[i - 1][j - 1] + vec[i][j];
            }
            else
            {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + vec[i][j];
            }
        }
    }

    int rst = 0;
    for (int i = 0; i < r; i++)
    {
        // cout << ans[r - 1][i] << " ";
        rst = max(rst, ans[r - 1][i]);
    }
    cout << rst;

    return 0;
}