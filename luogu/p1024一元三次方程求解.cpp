#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-3;

double a, b, c, d;

inline double func(double x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

void check(double l, double r)
{
    if (fabs(func(l)) < eps)
    {
        printf("%.2f ", l);
        return;
    }

    if (fabs(func(r)) < eps || func(l) * func(r) > 0)
        return;
    
    double mid = (l + r) / 2.0;
    check(l, mid);
    check(mid, r);
}

int main()
{
    cin >> a >> b >> c >> d;

    for (int i = -100; i < 100; i++)
        check(i, i + 1);
    
    return 0;
}