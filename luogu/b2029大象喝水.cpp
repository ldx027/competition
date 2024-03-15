#include <iostream>
using namespace std;

int main()
{
    int h, r;
    cin >> h >> r;
    double rl = 3.14 * r * r * h;
    double rst = 2e4 / rl;
    int ans = (rst == int(rst)) ? rst : rst + 1;
    cout << ans;

    return 0;
}