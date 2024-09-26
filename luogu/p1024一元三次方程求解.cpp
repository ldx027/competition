#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d;

double func(double x)
{
    return a * pow(x, 3) + b * pow(x, 2) + c * x + d;
}

int cnt = 0;
void query(double l, double r)
{
    if (cnt >= 3)
        return;

    if (r - l < 1e-3)
        return;

    if (fabs(func(l)) < 1e-6)
    {
        printf("%.2f ", l);
        cnt++;
        return;
    }

    if (func(l) * func(r) < 0) 
    {
        double m = (l + r) / 2;
        query(l, m);
        query(m, r);
    }
}

int main()
{
    cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; i++)
        query(i, i + 1);
    
    return 0;
}