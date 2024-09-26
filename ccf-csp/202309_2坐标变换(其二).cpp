#include <iostream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <iomanip>
using namespace std;

#define ll long long

#define debug

vector<int> cmd;
vector<double> val;
vector<double> scale;
vector<double> rotation;

int main()
{
    int n, m;
    cin >> n >> m;

    cmd.resize(n);
    val.resize(n);
    scale.resize(n + 1, 1);
    rotation.resize(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> cmd[i] >> val[i];

    for (int i = 0; i < n; i++)
    {
        if (cmd[i] == 1)
        {
            scale[i + 1] = val[i] * scale[i];
            rotation[i + 1] = rotation[i];
        }
        else if (cmd[i] == 2)
        {
            scale[i + 1] = scale[i];
            rotation[i + 1] = rotation[i] * val[i];
        }
    }

#ifdef debug
    for (int i = 0; i <= n; i++)
        cout << scale[i] << " ";
    cout << endl;
    for (int i = 0; i <= n; i++)
        cout << rotation[i] << " ";
    cout << endl;
#endif

    double l, r, x, y;
    while (m--)
    {
        cin >> l >> r >> x >> y;

        double len = sqrt(x * x + y * y);
        double r;
#ifdef debug
        cout << "len r ";
        cout << len << " " << r << endl;
#endif
        if (x == 0)
            r = y > 0 ? M_PI / 2 : -M_PI / 2;
        else
            r = atan2(y, x);

        len *= scale[r] / scale[l - 1];
        r += rotation[r] - rotation[l - 1];

        cout << fixed << setprecision(3) << len * cos(r) << " " << len * sin(r) << endl;
    }

    return 0;
}