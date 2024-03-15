#include <iostream>
using namespace std;

double max(double a, double b)
{
    return a > b ? a : b;
}

double min(double a, double b)
{
    return a < b ? a : b;
}

double range(double x, int _min, int _max)
{
    return min(_max, max(0, x));
}

int main()
{
    int x;
    cin >> x;
    double rst = 0;
    rst += range(x, 0, 150) * 0.4463;
    rst += range(x - 150, 0, 250) * 0.4663;
    rst += max(0, x - 400) * 0.5663;

    printf("%.1f", rst);

    return 0;
}