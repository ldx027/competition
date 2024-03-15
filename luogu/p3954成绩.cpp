#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double rst = a * 0.2 + b * 0.3 + c * 0.5;
    int ans = (rst == int(rst)) ? rst : rst + 1;
    cout << ans;

    return 0;
}