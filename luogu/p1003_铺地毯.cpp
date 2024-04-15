#include <iostream>
#include <vector>
using namespace std;

bool above(int x, int y, int xp, int yp, int xl, int yl)
{
    return ((x >= xp && x <= xp + xl) && (y >= yp && y <= yp + yl));
}

int main()
{
    int n, x, y;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(4));

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    cin >> x >> y;

    // 不用操作地面 将地毯存起来反着读到第一个覆盖的
    for (int i = n - 1; i >= 0; i--)
    {
        if (above(x, y, arr[i][0], arr[i][1], arr[i][2], arr[i][3]))
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}