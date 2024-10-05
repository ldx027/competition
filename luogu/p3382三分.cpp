#include <iostream>
#include <vector>
using namespace std;

int N;
double l, r;
vector<double> vec;

double func(double x)
{
    double base = x;
    double rst = vec[0];
    for (int i = 1; i <= N; i++)
    {
        rst += x * vec[i];
        x *= base;
    }

    return rst;
}

int main()
{
    cin >> N >> l >> r;

    vec.resize(N + 1);
    for (int i = N; i >= 0; i--)
        cin >> vec[i];

    while (r - l > 1e-7)    
    {
        double mid1 = l + (r - l) / 3;
        double mid2 = r - (r - l) / 3;

        double y1 = func(mid1);
        double y2 = func(mid2);

        if (y1 == y2)
            l = mid1, r = mid2;
        else if (y1 < y2)
            l = mid1;
        else if (y1 > y2)
            r = mid2;
    }

    cout << l << endl;

    return 0;
}