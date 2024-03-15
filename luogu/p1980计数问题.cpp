#include <iostream>
#include <cmath>
using namespace std;

int power(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++) rst *= x;
    return rst;
}

int digit(int x, int n)
{
    return x % power(10, n) / power(10, n - 1);
}

int main()
{
    int n, x;
    cin >> n >> x;

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= log10(i) + 1; j++)
        {
            if (digit(i, j) == x) ans++;
        }
    }

    cout << ans;

    return 0;
}