#include <iostream>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int m, t, s;
    cin >> m >> t >> s;
    if (t == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    double eat = double(s) / t;
    if (eat != int(eat)) eat += 1;
    cout << max(m - int(eat), 0) << endl;
    return 0;
}