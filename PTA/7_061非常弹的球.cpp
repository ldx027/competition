#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double Ek = 1000;
    double g = 9.8;

    double m;
    int p;
    cin >> m >> p;
    m /= 100;

    double total = 0;
    while (Ek > 1e-9)
    {
        double v = sqrt(2 * Ek / m);
        double vx = v / sqrt(2);
        double t = 2 * vx / g;
        double dis = t * vx;
        total += dis;
        Ek *= (100.0 - p) / 100;
    }

    printf("%.3lf", total);

    return 0;
}