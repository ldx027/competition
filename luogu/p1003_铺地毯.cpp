#include <iostream>
using namespace std;

bool above(int x, int y, int xp, int yp, int xl, int yl)
{
    return ((x >= xp && x <= xp + xl) && (y >= yp && y <= yp + yl));
}

int main()
{
    // 准备变量
    int n, x, y;
    cin >> n;
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[4];

    // 输入变量
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }
    cin >> x >> y;

    // solve
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