#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d;

double func(double);
void bin(double l, double r)
{
    // cout << l << " " << r << endl;
    if (!func(l))
    {
        printf("%.2f ", l);
        return;
    }

    if (func(l) * func(r) < 0)
    {
        if (r - l < 1e-3)
        {
            printf("%.2f ", l);
            return;
        }
        double mid = (r + l) / 2;
        if (func(l) * func(mid) < 0)
            bin(l, mid);
        else
            bin(mid, r);
    }
}

double func(double x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

int main()
{
    cin >> a >> b >> c >> d;

    for (int i = -100; i < 100; i++)
    {
        bin(i, i + 1);
    }

    return 0;
}