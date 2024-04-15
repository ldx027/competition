#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int w, x, h;
    cin >> w >> x >> h;

    bool vec[21][21][21] = { true };
    for (int i = 0; i < 21; i++)
    for (int j = 0; j < 21; j++)
    for (int k = 0; k < 21; k++)
    vec[i][j][k] = true;

    int q, x1, y1, z1, x2, y2, z2;
    cin >> q;

    while (q--)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                for (int u = z1; u <= z2; u++)
                {
                    vec[i][j][u] = false;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int u = 1; u <= h; u++)
            {
                cnt += vec[i][j][u];
            }
        }
    }

    cout << cnt << endl;

    return 0;
}