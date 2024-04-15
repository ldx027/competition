#include <iostream>
#include <cmath>
using namespace std;

int power(int base, int n)
{
    int rst = 1;
    while (n--) rst *= base;
    return rst;
}

int main()
{
    int n, R;
    cin >> n >> R;

    int digit = log(abs(n)) / log(-R) + 1;
    if (n < 0 && !(digit & 1)) digit++;
    // cout << digit << endl;

    cout << n << "=";

    int cur = n;
    for (int i = digit; i >= 0; i--)
    {
        int d = 0;
        if (i & 1)
        {
            while (cur < 0)
            {
                d = -cur / power(-R, i);
                cur -= power(R, i) * d;
            }
        }
        else
        {
            d = cur / power(R, i);
            cur -= power(R, i) * d;
        }

        cout << d;
    }

    cout <<"(base" << R << ")";

    return 0;
}