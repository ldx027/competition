#include <iostream>
using namespace std;

int main()
{
    int ans = 0;
    double s;
    double dis = 2;
    cin >> s;
    while (s > 0)
    {
        ans++;
        s -= dis;
        dis *= 0.98;
    }

    cout << ans << endl;

    return 0;
}